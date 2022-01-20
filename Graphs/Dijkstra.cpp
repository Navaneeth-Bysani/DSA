#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V);
        struct MinHeap *minHeap = createMinHeap(V);
        
        for(int i = 0; i<V; i++) {
            dist[i] = INT_MAX;
            minHeap->array[i] = newMinHeapNode(i, dist[i]);
            minHeap->pos[i] = i;
        }
        
        minHeap->array[S] = newMinHeapNode(S, dist[S]);
        minHeap->pos[S] = S;
        dist[S] = 0;
        decreaseKey(minHeap, S, dist[S]);
        minHeap->size = V;
        
        while(!isEmpty(minHeap)) {
            struct MinHeapNode* minHeapNode = extractMin(minHeap);
            int u = minHeapNode->v;
            for(auto v : adj[u]) {
                if(isInMinHeap(minHeap, v[0]) && dist[u] != INT_MAX && dist[v[0]] > dist[u] + v[1]) {
                    dist[v[0]] = dist[u] + v[1];
                    decreaseKey(minHeap, v[0], dist[v[0]]);
                }
            }
        }
        
        return dist;
    }
    
    private:
    //Heap+Map kind of data structure
    struct MinHeapNode {
        int v;
        int dist;
    };
    struct MinHeap {
        int Capacity;
        struct MinHeapNode **array;
        int *pos;
        int size;
    };
    bool isInMinHeap(struct MinHeap *minHeap, int v) {
        if (minHeap->pos[v] < minHeap->size)
            return true;
        return false;
    }
    bool isEmpty(struct MinHeap * minHeap) {
        return minHeap->size == 0;
    }
    
    struct MinHeapNode* newMinHeapNode(int v, int dist) {
        struct MinHeapNode *newMinHeapNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
        newMinHeapNode->v = v;
        newMinHeapNode->dist = dist;
        
        return newMinHeapNode;
    }
    struct MinHeap* createMinHeap(int capacity) {
        struct MinHeap *minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
        minHeap->pos = (int*)malloc(capacity * sizeof(int));
        minHeap->size = 0;
        minHeap->array = (struct MinHeapNode**)malloc(capacity*sizeof(struct MinHeapNode*));
        minHeap->Capacity = capacity;
        
        return minHeap;
    }
    int parent(int i) {
        return (i-1)/2;
    }
    void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
        struct MinHeapNode *x = *a;
        *a = *b;
        *b = x;
    }
    void minHeapify(struct MinHeap* minHeap, int idx) {
        int smallest, left, right;
        smallest = idx;
        left = 2 * idx + 1;
        right = 2 * idx + 2;
     
        if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist )
            smallest = left;
     
        if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist )
          smallest = right;
     
        if (smallest != idx)
        {
            
            MinHeapNode *smallestNode = minHeap->array[smallest];
            MinHeapNode *idxNode = minHeap->array[idx];
     
            
            minHeap->pos[smallestNode->v] = idx;
            minHeap->pos[idxNode->v] = smallest;
     
            
            swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
     
            minHeapify(minHeap, smallest);
        }
    }
    struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
        if (isEmpty(minHeap))
            return NULL;
        struct MinHeapNode* root = minHeap->array[0];   
        struct MinHeapNode *lastNode = minHeap->array[minHeap->size-1];
        minHeap->array[0] = lastNode;
        minHeap->pos[root->v] = minHeap->size-1;
        minHeap->pos[lastNode->v] = 0;
        --minHeap->size;
        minHeapify(minHeap, 0);
        
        return root;
    }
    void decreaseKey(struct MinHeap *minHeap, int v, int dist) {
        int i = minHeap->pos[v];
        minHeap->array[i]->dist = dist;
        while(i && minHeap->array[i]->dist < minHeap->array[parent(i)]->dist) {
            minHeap->pos[minHeap->array[i]->v] = parent(i);
            minHeap->pos[minHeap->array[parent(i)]->v] = i;
            
            swapMinHeapNode(&minHeap->array[i], &minHeap->array[parent(i)]);
            i = parent(i);
        }
    }  
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends