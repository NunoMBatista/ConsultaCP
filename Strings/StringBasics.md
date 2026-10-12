Básicos de strings: ler input (getline, partir em palavras/separador, até ao fim), limpar (minúsculas, só letras) e formatar output. Exemplos nos comentários.
```c++
// ===== LER =====
cin >> n; cin.ignore();                  // antes de getline, senao o 1o getline vem vazio
getline(cin, line);                      // linha inteira com espacos: "ola mundo 42"

stringstream ss(line);                   // partir em palavras: "ola mundo 42" -> "ola", "mundo", "42"
while (ss >> w) { }

stringstream ss2("a,b,,c");              // partir por separador: "a,b,,c" -> "a", "b", "", "c"
while (getline(ss2, part, ',')) { }

while (getline(cin, line)) { }           // ler linhas ate ao fim do input (quando nao dao N)

sscanf("14:35", "%d:%d", &h, &m);        // formato fixo: "14:35" -> h = 14, m = 35

// ===== LIMPAR =====
for (char &c : s) c = tolower(c);        // "OlA Mundo" -> "ola mundo"
s.erase(remove_if(all(s), [](char c){ return !isalpha(c); }), s.end());   // "a, b!" -> "ab"

// ===== ESCREVER =====
cout << fixed << setprecision(2) << x;                          // 3.14159 -> "3.14"
cout << setfill('0') << setw(2) << h << ":" << setw(2) << m;    // 7, 5 -> "07:05"
// alinhar a esquerda em 10 colunas: "Ana" -> "Ana       |"
// (setfill/left ficam ativos; setw so vale 1 vez)
cout << setfill(' ') << left << setw(10) << nome << "|";
```
