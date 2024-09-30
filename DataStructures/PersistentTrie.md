Estrutura que guarda e altera strings procuradas
Complexidade: ?
```c++
// Node for lowercase strings
struct Node {
	array<shared_ptr<Node>, 26> children;
	bool end;     // whether this node represents the end of a key
	size_t count; // optional (depending on queries)

	Node() : children{}, end{false}, count{0}  {}
};

class Trie {
private:
	shared_ptr<Node> root;
	explicit Trie(shared_ptr<Node> root) : root(root) {}

public:
	Trie() : root(new Node()) {}
	size_t size() const {
	return root->count;
	}

	bool exists(string_view s) const {
		auto node = root;
		for (auto c : s) {
			auto idx = c - 'a';
			if (node->children[idx]) {
				node = node->children[idx];
			} else {
				return false;
			}
		}
		return node->end;
	}

	optional<Trie> insert(string_view s) {
		if (exists(s)) {
			return {};
		}

		auto nroot = make_shared<Node>(*root);
		auto node = nroot;
		node->count += 1;
		for (auto c : s) {
			auto idx = c - 'a';
			if (node->children[idx]) {
				node = node->children[idx] = make_shared<Node>(*(node->children[idx]));
			} else {
				node = node->children[idx] = make_shared<Node>();
			}
			node->count += 1;
		}
		node->end = true;
		return Trie(nroot);
	}

	size_t count(string_view prefix) const {
		auto node = root.get();
		for (auto c : prefix) {
			auto idx = c - 'a';
			if (node->children[idx]) {
				node = node->children[idx].get();
			} else {
				return 0;
			}
		}
		return node->count;
	}
};
```
