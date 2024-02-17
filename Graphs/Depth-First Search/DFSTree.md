The DFS tree of a graph is created by traversing a graph with DFS and marking every edge that was traveled as such:

```
1 function visit(u):
2     mark u as visited
3     for each vertex v among the neighbours of u:
4         if v is not visited:
5             mark the edge uv
6             call visit(v)
```

The unmarked edges are called *back-edges* and and the marked ones are called *span-edges/tree-edges.*

The backedges all connect a vertex with it's descendant. 

This simplifies the graph since we are now dealing with a spanning-tree.
