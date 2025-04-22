#include <bits/stdc++.h>
using namespace std;

struct Question
{
    int question_number;
    double marks;
    double time;
    double ratio;
};

bool compare(Question a, Question b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int M, T, N;
    cin >> M >> T >> N;
    vector<Question> questions(N);
    for (int i = 0; i < N; i++)
    {
        double p, d;
        cin >> p >> d;
        questions[i].question_number = i + 1;
        questions[i].marks = p;
        questions[i].time = d;
        questions[i].ratio = (double)p / d;
    }

    sort(questions.begin(), questions.end(), compare);

    // (a) Maximizing marks alone
    double remaining_time = T;
    double total_marks = 0;
    vector<tuple<int, double, double>> selected_questions;
    for (int i = 0; i < N; i++)
    {
        if (remaining_time <= 1e-9)
            break;
        double take_time = min(questions[i].time, remaining_time);
        double percent = take_time / questions[i].time;
        double marks_got = questions[i].marks * percent;
        if (take_time > 1e-9)
        {
            selected_questions.push_back({questions[i].question_number, percent * 100, marks_got});
            total_marks += marks_got;
            remaining_time -= take_time;
        }
    }

    cout << "Maximum " << (int)total_marks << " marks answering alone" << endl;
    for (const auto &question : selected_questions)
    {
        int idx;
        double percent, taken_marks;
        tie(idx, percent, taken_marks) = question;
        cout << "ques " << idx << " " << fixed << setprecision(0) << percent << "% done -- " << setprecision(0) << taken_marks << " marks" << endl;
    }

    // (c) Maximizing marks with a friend (two people, each with T minutes)
    // Use a max-heap for questions and a min-heap for person availability
    struct HeapQ
    {
        double ratio;
        int idx;
        bool operator<(const HeapQ &other) const
        {
            return ratio < other.ratio; // max-heap
        }
    };
    priority_queue<HeapQ> pq;
    for (int i = 0; i < N; ++i)
    {
        pq.push({questions[i].ratio, i});
    }
    // Each person: (available_time_left)
    vector<double> person_time(2, T);
    double group_marks = 0;
    while (!pq.empty() && (person_time[0] > 1e-9 || person_time[1] > 1e-9))
    {
        // Pick the next best question
        HeapQ top = pq.top();
        pq.pop();
        int idx = top.idx;
        // Assign to the person with more time left
        int who = (person_time[0] >= person_time[1]) ? 0 : 1;
        if (person_time[who] <= 1e-9)
            continue;
        double take_time = min(questions[idx].time, person_time[who]);
        double percent = take_time / questions[idx].time;
        double marks_got = questions[idx].marks * percent;
        group_marks += marks_got;
        person_time[who] -= take_time;
        // If not fully done, push the remaining part back into the heap
        if (percent < 1.0 && (questions[idx].time - take_time) > 1e-9)
        {
            Question q = questions[idx];
            q.time = questions[idx].time - take_time;
            q.marks = questions[idx].marks - marks_got;
            q.ratio = q.marks / q.time;
            questions.push_back(q);
            pq.push({q.ratio, (int)questions.size() - 1});
        }
    }
    cout << "Maximum " << (int)group_marks << " marks answering with a friend" << endl;

    return 0;
}