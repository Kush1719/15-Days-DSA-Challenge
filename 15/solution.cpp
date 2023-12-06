vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){	
	vector<int> ADJ[n+1];	
	for(int i = 0 ; i < m ; i++ ){
		int X , Y;
		X=edges[i].first;
		Y=edges[i].second;
		ADJ[X].push_back(Y);
		ADJ[Y].push_back(X);
	}
    vector<int> visited(n+1,-1);
	vector<int> parent(n+1,-1);
	visited[s]=1;
	queue<int> Q;
    Q.push(s);
    while(Q.size()>0) {
		int currentNode = Q.front();
		Q.pop();
        for(int nextNode : ADJ[currentNode] ) {
            if( visited[nextNode]==-1 ) {
				visited[nextNode]=1;
				Q.push(nextNode);
				parent[nextNode]=currentNode;
			}
		}
	}
	vector<int> path;
	int currentNode =  t;
	path.push_back(t);
    while(currentNode != s) {
        currentNode = parent[currentNode];
		path.push_back(currentNode);	
	}
	reverse(path.begin() , path.end());
	return path;
}