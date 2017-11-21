# MST_NETWORK
Minimum Spanning Tree for network topology.
## Steps of Project:
### - MST Algorithm
### - MST Implementation
### - Extern Input Graph
### - Datas by IP/MASK/GATEWAY in Vertices

Minimum spanning tree for computer network topology example

References:
https://www.youtube.com/watch?v=Xmwmezk75Tk
<p>
http://slideplayer.com/slide/8807967/
<p>
  
# Borůvka's algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-9-boruvkas-algorithm/
https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm
  
# Prim's
https://en.wikipedia.org/wiki/Prim%27s_algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/
http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/

<p>
# Kruskal's
https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
<p>
  
# Extras:
Definições do Projeto:
- Ler um arquivo .dot com os dados  do grafo
- Os pesos de cada linha depois podem ser a velocidade do cabo inves de inteiros
- Parâmetro do ponto de rede: TYPE - IP ADDRESS/MASK - GATEWAY(eh o roteador. parametro somente de HOST e roteador)? - MAC ADDRESS (Tipos: Roteador(Raiz) -> Switch(Subárvore) -> HOST(Folha))
- Grafo: Será dos componentes interligados de uma rede de computadores e não a ligação entre redes em si.
- Aplicação: Um empresa com varios setores e computadores interligados

Slides:

- Exemplos de aplicações do MST
- Mostrar o funcionamento do algoritmo de Kruskal
- Transforma de Grafo para Árvore
- Falar dos fundamentos de uma rede de computadores
- Os pesos podem ser: Velocidade, distancia, tempo, custo monetário, etc...


Spanning-Tree Protocol (STP) is designed to prevent problems related to bridging loops.


It solves the issue by blocking redundant paths and allowing only a single active path. STP works by choosing a root switch then selecting a loop free path from the root switch to every other switch. To do that, spanning tree must elect a single root bridge, one root port for each non-root switch, and a single designated port for each network segment.
