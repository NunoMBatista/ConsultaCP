Backtracking template: make a move, explore everything after it, undo the move. Only the small problem-specific functions change; backtrack() stays the same.
Example: MIUP 2021 E (Chemical Names). Complexity: exponential, so check the size limits at the bottom first.
```c++
// BACKTRACKING: build a solution one move at a time; after exploring a move, undo it.
// Only the small functions change between problems; backtrack() is always the same.
// Example (MIUP 2021 E): write a name with chemical element symbols, "alves" -> al v es

string name;                            // input, lowercase
set<string> elementSymbols;             // lowercase symbols: "h", "he", "al", ...
int position = 0;                       // how many letters of the name are already covered
vector<string> chosenSymbols;           // moves made so far = the partial solution

// Is the current partial solution finished?
bool isCompleteSolution(){ return position == (int)name.size(); }

// List every move that is allowed from the current state
vector<string> possibleMoves(){
	vector<string> moves;
	for (int length = 1; length <= 2; length++){
		if (position + length > (int)name.size()) break;
		string piece = name.substr(position, length);
		if (elementSymbols.count(piece)) moves.push_back(piece);
	}
	return moves;
}

// Make a move: update the state
void applyMove(const string& symbol){
	chosenSymbols.push_back(symbol);
	position += symbol.size();
}

// Undo a move: put the state back exactly as it was before applyMove
void undoMove(const string& symbol){
	chosenSymbols.pop_back();
	position -= symbol.size();
}

// What to do with each complete solution (the goal): here, print it.
// To count instead: solutionCount++;   To find the best: compare and keep it.
void handleSolution(){
	for (const string& symbol : chosenSymbols) cout << symbol << " ";
	cout << "\n";
}

// Try every move, go deeper, undo; reaches every complete solution once
// int depth = 0;
void backtrack(){
	if (isCompleteSolution()){ handleSolution(); return; }
	// pruning goes here: if (this branch can no longer reach a solution) return;
	for (const string& move : possibleMoves()){
		// cerr << string(2 * depth, ' ') << "try " << move << "\n";
		applyMove(move);    // depth++;
		backtrack();
		undoMove(move);     // depth--;
	}
}

// COUNT VERSION: how many complete solutions can be reached from the current state.
// Same helper functions as above. The memo makes it fast: each state is solved only once.
map<int, long long> countMemo;          // state (here: position) -> number of solutions

long long countSolutions(){
	if (isCompleteSolution()) return 1;
	if (countMemo.count(position)) return countMemo[position];   // state already solved
	long long total = 0;
	for (const string& move : possibleMoves()){
		applyMove(move);
		total += countSolutions();
		undoMove(move);
	}
	return countMemo[position] = total;
}
```
