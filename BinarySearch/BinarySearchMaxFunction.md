Example: \
I want to find the largest index $i$ in the array $1, 1, 1, 1, 0, 0, 0, 0, 0$ that is still a $1$

```
bool F(ll target){
  if(array[target] == 1)
    return true;
  else
    return false;
}
```
The algorithm starts by searching in the index $0+(9-0)/2 = 4$, $array[4] = 1 \implies leftBound$ is now $4$  

Next, it will search in the index $4+(9-4)/2 = 6$, $array[6] = 0 \implies rightBound$ is now $6$  

Next, it will seatch in the index $4+(6-4)/2 = 5$, $array[5] = 0 \implies rightBound$ is now $5$  

This breaks the condition $rightBound > leftBound + 1$, so it returns $leftBound = 4$  

```c++
bool F(ll target){
    return true or false;
}

ll bestXforF (){
    ll leftBound = 0, rightBound = 1, mid;
    
    while(F(rightBound) == false)
        rightBound *= 2;

    while(rightBound > leftBound + 1){
        mid = leftBound + (rightBound - leftBound)/2;
        if(F(mid) == true)
            rightBound = mid;
        else    
            leftBound = mid;
    }

    return leftBound;
}

```
