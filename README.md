# MST_NETWORK
Minimum Spanning Tree for computer network topology.
## Features:
### - MST Implementation
### - Receive .csv graph
### - Output Graph .dot
### - Datas by IP/MASK/GATEWAY in Vertices

Minimum spanning tree for computer network topology example

References:
# Borůvka's algorithm
https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-9-boruvkas-algorithm/
  
# Prim's
https://en.wikipedia.org/wiki/Prim%27s_algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/

<p>
# Kruskal's
https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
<p>
  
# Extras:
Definições do Projeto:
- Ler um arquivo .dot com os dados  do grafo
- Os pesos de cada linha depois podem ser a velocidade do cabo inves de inteiros
- Parâmetro do vértice: TYPE - IP ADDRESS/MASK - GATEWAY - MAC ADDRESS (Tipos: Roteador(Raiz) -> Switch(Subárvore) -> HOST(Folha))
- Grafo: Será dos componentes interligados de uma rede de computadores e não a ligação entre redes em si.
- Aplicação: Um empresa com varios setores e computadores interligados
