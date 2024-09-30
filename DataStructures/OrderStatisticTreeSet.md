Estruturas que permite armazenar valores (nao repetidos) numa arvore. A inserção é ordenada.
Complexidade: Inserção, remoção e perquisa - O(log(N)) sendo N = numero de valores já guardados
```c++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using oset = tree<int,         // key type
		null_type,   // value type
		less<int>,   // compare function
		rb_tree_tag,
		tree_order_statistics_node_update>;
        //find_by_order returns pointers
        //order_of_key returns int
auto s = oset();
```
