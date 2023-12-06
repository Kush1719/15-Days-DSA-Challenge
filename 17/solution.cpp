int findCelebrity(int n) {
    int p = 0, q = n-1; 
    while(p < q) {
        if(knows(p, q)) {
            p++;  
        }
        else {
            q--; 
        }
    }
    int celebrity = p;
    bool knowAny = false, knownToAll = true;
    for(int i = 0; i < n; i++) {
        if(knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }
    if(knowAny or !knownToAll) {
        celebrity = -1;
    }
    return celebrity;
}