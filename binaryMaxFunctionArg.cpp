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

/*
Exemplo: 
Quero encontrar o maior index X do array 111100000 que ainda é 1

bool F(ll target)
    if(array[target] == 1)
        return true;
    else
        return false

Começo por procurar no index 0+(9-0)/2 = 4, como array[4] == 1, o leftBound passa a ser 4

A seguir procura no index 4+(9-4)/2 = 6, como array[6] == 0, o rightBound passa a ser 6

A seguir procura no index 4+(6-4)/2 = 5, como array[5] == 0, o rightBound passa a ser 5

Isto quebra a condição rightBound > leftBound + 1, retornando assim leftBound = 4
*/