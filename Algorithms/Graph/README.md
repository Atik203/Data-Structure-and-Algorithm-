# Graph Algorithms Guide - Exam Reference

## Table of Contents
1. [Algorithm Overview](#algorithm-overview)
2. [Decision Flowchart](#decision-flowchart)
3. [Dijkstra's Algorithm](#dijkstras-algorithm)
4. [Bellman-Ford Algorithm](#bellman-ford-algorithm)
5. [Kruskal's Algorithm](#kruskals-algorithm)
6. [Prim's Algorithm](#prims-algorithm)
7. [Quick Reference Table](#quick-reference-table)
8. [Sample Exam Problems](#sample-exam-problems)
9. [Algorithm Selection Strategy](#algorithm-selection-strategy)

---

## Algorithm Overview

| Algorithm | Purpose | Time Complexity | Use Case |
|-----------|---------|----------------|----------|
| **Dijkstra** | Single Source Shortest Path | O(V²) or O(E log V) | Positive weights only |
| **Bellman-Ford** | Single Source Shortest Path + Cycle Detection | O(VE) | Negative weights allowed |
| **Kruskal** | Minimum Spanning Tree | O(E log E) | Edge-based MST |
| **Prim** | Minimum Spanning Tree | O(V²) or O(E log V) | Vertex-based MST |

---

## Decision Flowchart

```
📝 PROBLEM ANALYSIS
│
├── 🎯 Need SHORTEST PATH from one vertex to others?
│   │
│   ├── ❌ Has NEGATIVE edge weights?
│   │   └── YES → 🔴 **BELLMAN-FORD ALGORITHM**
│   │
│   └── ✅ Only POSITIVE/ZERO weights?
│       └── YES → 🟢 **DIJKSTRA'S ALGORITHM**
│
└── 🔗 Need to CONNECT ALL vertices with MINIMUM TOTAL COST?
    │
    └── YES → 🟡 **KRUSKAL'S** or **PRIM'S ALGORITHM** (MST)
```

---

## Dijkstra's Algorithm

### 🎯 **What it solves:**
- **Single Source Shortest Path (SSSP)** with non-negative weights
- Finds shortest distance from source to all other vertices

### 🔍 **When to use:**
- All edge weights are **positive or zero**
- Need shortest path from one vertex to all others
- GPS navigation, network routing

### 📝 **Problem Keywords:**
- "shortest path", "minimum distance", "optimal route"
- "fastest way", "least cost path"
- **Important: NO negative weights**

### 🧪 **Example Problems:**

#### Problem 1: City Navigation
```
"Find the shortest route from Mumbai to all other cities in India. 
The distances between cities are all positive values."

Solution: Use Dijkstra's Algorithm
- Source: Mumbai
- Find shortest distance to all cities
- All distances are positive ✅
```

#### Problem 2: Network Routing
```
"In a computer network, find the path with minimum latency 
from server A to all other servers. All latencies are positive."

Solution: Use Dijkstra's Algorithm
- Source: Server A
- Minimize total latency
- All weights positive ✅
```

#### Problem 3: Delivery Service
```
"A delivery truck needs to find the shortest route from warehouse 
to all customer locations. Travel times are all positive."

Solution: Use Dijkstra's Algorithm
- Source: Warehouse
- Minimize delivery time
- All times positive ✅
```

### ⚠️ **When NOT to use:**
- Graph has negative edge weights
- Need to detect negative cycles
- Only need to connect vertices (MST problem)

---

## Bellman-Ford Algorithm

### 🎯 **What it solves:**
- **Single Source Shortest Path** with negative weights allowed
- **Negative cycle detection**
- Works with any edge weights (positive, negative, zero)

### 🔍 **When to use:**
- Graph contains **negative edge weights**
- Need to detect **negative weight cycles**
- Currency exchange, arbitrage detection

### 📝 **Problem Keywords:**
- "negative weights", "negative costs"
- "arbitrage opportunities", "currency exchange"
- "detect negative cycles"

### 🧪 **Example Problems:**

#### Problem 1: Currency Exchange
```
"Find the most profitable currency exchange path from USD to all 
other currencies. Some exchange rates result in losses (negative values)."

Solution: Use Bellman-Ford Algorithm
- Source: USD
- Handle negative exchange rates ✅
- Detect arbitrage (negative cycles) ✅
```

#### Problem 2: Stock Trading
```
"In a trading system, some transactions have fees (negative profits). 
Find the path with maximum profit and detect arbitrage opportunities."

Solution: Use Bellman-Ford Algorithm
- Handle negative transaction costs ✅
- Detect arbitrage cycles ✅
```

#### Problem 3: Game Scoring
```
"In a game, some moves give negative scores. Find the path from 
start to all positions with maximum score and detect infinite loops."

Solution: Use Bellman-Ford Algorithm
- Handle negative scores ✅
- Detect negative cycles (infinite scoring) ✅
```

### ⚠️ **When NOT to use:**
- All weights are positive (Dijkstra is faster)
- Need MST (use Kruskal/Prim)

---

## Kruskal's Algorithm

### 🎯 **What it solves:**
- **Minimum Spanning Tree (MST)**
- Connects all vertices with minimum total edge weight
- Results in a tree (V-1 edges, no cycles)

### 🔍 **When to use:**
- Need to connect all vertices with **minimum total cost**
- Build network infrastructure
- **Edge-based approach** (good for sparse graphs)

### 📝 **Problem Keywords:**
- "connect all", "minimum cost", "spanning tree"
- "network design", "infrastructure"
- "minimum total", "least expense"

### 🧪 **Example Problems:**

#### Problem 1: Network Cable Installation
```
"Connect all 8 computers in an office with network cables. 
Find the minimum length of cable needed to connect all computers."

Solution: Use Kruskal's Algorithm
- Connect all computers ✅
- Minimize total cable length ✅
- Result: Tree structure (no cycles) ✅
```

#### Problem 2: Power Grid Design
```
"Design an electrical power grid to connect 10 cities. 
What's the minimum cost to ensure all cities are connected?"

Solution: Use Kruskal's Algorithm
- Connect all cities ✅
- Minimize total construction cost ✅
- Ensure connectivity ✅
```

#### Problem 3: Road Construction
```
"Build roads to connect 6 villages. Find the minimum cost road 
network that connects all villages."

Solution: Use Kruskal's Algorithm
- Connect all villages ✅
- Minimize road construction cost ✅
- No redundant connections ✅
```

#### Problem 4: Pipeline Network
```
"Install water pipelines to connect all districts in a city. 
Minimize the total pipeline length needed."

Solution: Use Kruskal's Algorithm
- Connect all districts ✅
- Minimize total pipeline length ✅
```

### 🔧 **Algorithm Steps:**
1. Sort all edges by weight (ascending)
2. Use Union-Find to detect cycles
3. Add edges that don't create cycles
4. Stop when V-1 edges are added

---

## Prim's Algorithm

### 🎯 **What it solves:**
- **Minimum Spanning Tree (MST)** (same as Kruskal)
- Connects all vertices with minimum total edge weight
- **Vertex-based approach** (good for dense graphs)

### 🔍 **When to use:**
- Same problems as Kruskal's
- **Dense graphs** (many edges)
- When you prefer vertex-based growth

### 📝 **Problem Keywords:**
- Same as Kruskal's - both solve MST problems
- "connect all", "minimum cost", "spanning tree"

### 🧪 **Example Problems:**

#### Same problems as Kruskal's:
```
1. "Minimum cost to connect all computers in network"
2. "Design electrical grid with minimum cable"
3. "Connect all islands with bridges (minimum cost)"
4. "Build minimum cost road network connecting all towns"
```

### 🔧 **Algorithm Steps:**
1. Start from any vertex
2. Always add the minimum weight edge that connects a visited vertex to an unvisited vertex
3. Continue until all vertices are included

### 🆚 **Kruskal vs Prim:**
- **Kruskal:** Edge-based, good for sparse graphs
- **Prim:** Vertex-based, good for dense graphs
- **Both produce the same MST weight**

---

## Quick Reference Table

| Problem Type | Algorithm | Key Indicators | Example |
|--------------|-----------|----------------|---------|
| **Shortest Path (Positive Weights)** | Dijkstra | "shortest", "minimum distance", positive weights | GPS navigation |
| **Shortest Path (Any Weights)** | Bellman-Ford | "negative weights", "arbitrage", "cycle detection" | Currency exchange |
| **Connect All (Minimum Cost)** | Kruskal/Prim | "connect all", "minimum total cost", "spanning tree" | Network design |

---

## Sample Exam Problems

### 🔴 **Type 1: Shortest Path with Positive Weights → Dijkstra**

#### Problem A:
> "A logistics company wants to find the shortest delivery route from their main warehouse to all 15 customer locations. All travel times between locations are positive. Which algorithm should be used?"

**Answer:** Dijkstra's Algorithm
- **Reason:** Shortest path problem + positive weights

#### Problem B:
> "Find the fastest route for emergency services from the hospital to all accident locations in the city. All travel times are positive."

**Answer:** Dijkstra's Algorithm
- **Reason:** Single source shortest path + positive weights

### 🔴 **Type 2: Shortest Path with Negative Weights → Bellman-Ford**

#### Problem C:
> "A forex trader wants to find the most profitable currency exchange sequence from USD to all other currencies. Some exchanges result in losses (negative profits). Also detect if infinite profit is possible."

**Answer:** Bellman-Ford Algorithm
- **Reason:** Negative weights + cycle detection needed

#### Problem D:
> "In a game, some moves give penalty points (negative scores). Find the path with maximum score from start to all positions and detect if infinite scoring is possible."

**Answer:** Bellman-Ford Algorithm
- **Reason:** Negative weights + negative cycle detection

### 🔴 **Type 3: Minimum Spanning Tree → Kruskal/Prim**

#### Problem E:
> "Design a communication network to connect 12 offices of a company. Find the minimum cost cable layout that ensures all offices can communicate with each other."

**Answer:** Kruskal's or Prim's Algorithm
- **Reason:** Connect all vertices + minimum total cost = MST

#### Problem F:
> "Build a water pipeline system to connect 8 districts in a city. What's the minimum total pipeline length needed to ensure water reaches all districts?"

**Answer:** Kruskal's or Prim's Algorithm
- **Reason:** Connect all + minimize total length = MST

#### Problem G:
> "Connect all villages in a region with roads such that the total construction cost is minimized and every village is reachable from every other village."

**Answer:** Kruskal's or Prim's Algorithm
- **Reason:** Connect all + minimum cost + reachability = MST

---

## Algorithm Selection Strategy

### 📋 **Step-by-Step Decision Process:**

#### Step 1: Identify Problem Type
```
🤔 Ask yourself:
- Do I need SHORTEST PATH from one vertex to others?
- Do I need to CONNECT ALL vertices with minimum cost?
```

#### Step 2: Check for Special Conditions
```
If SHORTEST PATH:
  ├── Are all weights POSITIVE? → Dijkstra ✅
  └── Are there NEGATIVE weights? → Bellman-Ford ✅

If CONNECT ALL:
  └── Any weights → Kruskal or Prim ✅
```

#### Step 3: Look for Keywords
```
🔍 Shortest Path Keywords:
- "shortest", "fastest", "minimum distance"
- "optimal route", "least time"

🔍 Negative Weight Keywords:
- "negative", "loss", "penalty"
- "arbitrage", "currency exchange"

🔍 MST Keywords:
- "connect all", "minimum total cost"
- "network design", "infrastructure"
- "spanning tree", "minimum cable"
```

### ⚡ **Quick Decision Rules:**

1. **See "shortest path" + "positive weights"** → **Dijkstra**
2. **See "shortest path" + "negative weights"** → **Bellman-Ford**
3. **See "connect all" + "minimum cost"** → **Kruskal/Prim**
4. **See "currency exchange" or "arbitrage"** → **Bellman-Ford**
5. **See "network design" or "infrastructure"** → **Kruskal/Prim**

---

## Common Exam Tricks & Tips

### ⚠️ **Watch Out For:**

1. **Hidden Negative Weights:**
   - "Some costs are penalties" → Negative weights → Bellman-Ford
   - "Profit/Loss scenarios" → Can have negative values

2. **MST vs Shortest Path Confusion:**
   - "Connect all with minimum **TOTAL** cost" → MST (Kruskal/Prim)
   - "Shortest path from A to B" → Shortest Path (Dijkstra/Bellman-Ford)

3. **Multiple Valid Answers:**
   - For MST: Both Kruskal and Prim are correct
   - Choose based on graph density (sparse→Kruskal, dense→Prim)

### ✅ **Success Tips:**

1. **Read the problem twice**
2. **Identify key phrases** (shortest, connect all, negative, etc.)
3. **Check weight properties** (positive/negative)
4. **Use the decision flowchart**
5. **Verify your choice** with the problem requirements

---

## Memory Aids

### 🧠 **Remember These:**

- **D**ijkstra → **D**istance (positive only)
- **B**ellman-Ford → **B**ad weights (negative) + **B**ounce detection (cycles)
- **K**ruskal → **K**eep adding edges (edge-based MST)
- **P**rim → **P**ick vertices (vertex-based MST)

### 📚 **Final Checklist Before Exam:**

- [ ] I can identify shortest path problems
- [ ] I can distinguish positive vs negative weights
- [ ] I can recognize MST problems
- [ ] I know when to use each algorithm
- [ ] I can solve sample problems correctly

---

**Good Luck with Your Exam! 🍀**

*Remember: Practice with sample problems and always read the problem statement carefully to identify the correct algorithm.*
