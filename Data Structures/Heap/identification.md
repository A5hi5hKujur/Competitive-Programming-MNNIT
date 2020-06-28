
  IDNTNTIFICATION OF HEAP :

  1. Elements would need to be sorted (smallest, biggest, top, bottom, nearest, furthest,...etc).
  2. "K" parameter would be provided.

  Eg, Find the K largest, Find the K smallest, K Closest Number... etc.

  In order to solve the problems you would require either :
  1. Min Heap : If K-largest needs to be found.
  2. Max Heap : If K-smallest needs to be found.

  OPTIMIZATION :

  Q. Why not use simple sort function and then determine the kth ?
  A. Sorting has a time complexity of O(nlogn), but since we only need to find k
     largest or k smallest, any number outside that range need not be sorted.

     We can keep out computation time short if we only sort elements from arr[1] to
     arr[k] (1 based indexing) and return the kth index. bringing our Time
     complexity down to O(nlogk).

  IMPLIMENTATION :

  1. Max Heap : priority_queue<int> max_heap;
                 - top() : returns the max element.
  2. Min Heap : priority_queue<int, vector<int>, greater<int>> min_heap;
                 - top() : returns the min element.

   Operation :
      1. size() : Displays heap size.
                    Syntax : max_heap.size();
      2. push() : Pushes new element in the heap.
                    Syantax : max_heap.push(i);
      3. pop() : Removes top element from the heap.
                    Syntax : max_heap.pop();

  typedef pair<int,int> pi;
          1. priority_queue<pi> max_heap;
          2. priority_queue<pi, vector<pi>, greater<pi>> min_heap;
