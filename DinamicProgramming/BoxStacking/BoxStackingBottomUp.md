Given $n$ boxes $[(L_1, W_1, H_1), (L_2, W_2, H_2), ... \space, (L_n, W_n, H_n)]$ where box $i$ has length $L_i$, width $W_i$ and height $H_i$, find the height of the tallest possible stack. Box $i$ can only be on top of box $j$ if $L_i < L_j \land W_i < W_j$.

Structure the problem as a directed graph where the edges are connected between two boxes if the box on the left can be stacked on the box on the right. Every path in the graph corresponds to a possible stack of boxes, so we need to find the path that gives the tallest height.


The tallest stack with box $i$ at the base will be cached in $heights[i]$.

When iterating through every box, a vector $S$ with every height of the boxes that can be stacked on top of box $i$, and the $heights$ vector will be updated acordingly: $heights[i] = heights[i] + \max\\{i \space | \space i \in S\\}$.

```c++
bool compareLength(vll Box1, vll Box2){
    return Box1[0] < Box2[0];
}

bool canBeStacked(ll wTop, ll lTop, ll wBottom, ll lBottom){
    return wTop < wBottom && lTop < lBottom;
}

ll tallestStack (vvll boxes, ll n){
    sort(all(boxes), compareLength); // sort all boxes by length 
    map<vll, ll> heights; // memoize the tallest stack with box n at the base
    for(auto box: boxes){
        heights[box] = box[2];
    }

    for(auto box_i: boxes){
        vll S; // vector of heights of stacks starting at boxes that can be stacked on top of box_i
        for(auto j: boxes){
            if(canBeStacked(j[1], j[0], box_i[1], box_i[0]))
                S.pub(heights[j]);
        }
        if(!S.empty())
            heights[box_i] = heights[box_i] + (*max_element(all(S)));
    }

    ll maxHeight = 0; 
    for(auto i: heights){
        if(i.second > maxHeight)
            maxHeight = i.second;
    }
    return maxHeight;
}

void solve(){
    ll n = 6;
    vvll boxes = {{1, 2, 2}, {1, 5, 4}, {2, 3, 2}, {2, 4, 1}, {3, 6, 2}, {4, 5, 3}};
    cout << tallestStack(boxes, n) << endl;
}
```
