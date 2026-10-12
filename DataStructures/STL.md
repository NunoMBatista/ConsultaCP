Map, set and priority_queue basics: iterate (both directions), check a key, first/last element, lower_bound, erase while iterating, heaps.
```c++
map<string, int> wordCount;                    // sorted by key; wordCount["x"] creates "x" with 0
for (auto& [word, count] : wordCount) cout << word << " " << count << "\n";
if (wordCount.count("x")) { }                  // check a key without creating it

set<int> values = {5, 1, 3};                   // sorted, no duplicates (multiset allows them)
for (int value : values) cout << value << " "; // 1 3 5
int smallest = *values.begin(), largest = *values.rbegin();
// reverse order: 5 3 1
for (auto current = values.rbegin(); current != values.rend(); current++)
	cout << *current << " ";
auto firstAtLeast2 = values.lower_bound(2);    // first >= 2 -> 3 (may be values.end())
for (auto current = values.begin(); current != values.end(); )   // erase while iterating
	if (*current % 2) current = values.erase(current); else current++;

// unordered_map / unordered_set: same syntax, faster, NOT sorted
priority_queue<int> maxHeap;                   // largest on top
priority_queue<int, vi, greater<int>> minHeap; // smallest on top
maxHeap.push(4); int topValue = maxHeap.top(); maxHeap.pop();
```
