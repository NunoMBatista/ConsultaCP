Estrutura que permite guardar keys (únicas) e seus respetivos valores numa arvore.
Complexidade: Inserção, remoção e pesquisa - O(log(N)) sendo N = numeros de keys guardadas
```c++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using omap = tree<int,         // key type
		int,         // value type
		less<int>,   // compare function
		rb_tree_tag,
		tree_order_statistics_node_update>;
auto m = omap();
```
