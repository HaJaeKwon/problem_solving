#include <iostream>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

// �׷��� Ÿ�� ����
typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;

// �׷����� vertex index�� property_map�� �Ӽ����� ���Ͽ� Ÿ�� ����
typedef property_map<Graph, vertex_index_t>::type IndexMap;


template <class Graph> struct exercise_vertex {

	// functor ����
	exercise_vertex(Graph& g_) : g(g_) {}

	// �׷��� ����
	Graph& g;

	// vertex Ÿ�� ���� 
	typedef typename graph_traits<Graph>::vertex_descriptor Vertex;

	// ()������ �����ε�
    void operator()(const Vertex& v) const {
      typedef graph_traits<Graph> GraphTraits;
      typename property_map<Graph, vertex_index_t>::type index = get(vertex_index, g);

	  // Out-Edges
      std::cout << "out-edges: ";
	  // out_edge iterator, edge ����
      typename GraphTraits::out_edge_iterator out_i, out_end;
      typename GraphTraits::edge_descriptor e;
      for (boost::tie(out_i, out_end) = out_edges(v, g); out_i != out_end; ++out_i) {
		  // �������� ���� out_edge ���� ���
		  e = *out_i;
		  Vertex src = source(e, g), targ = target(e, g);
		  std::cout << "(" << index[src] << "," << index[targ] << ") ";
	  }
	  std::cout << std::endl;

	  // In-Edges
	  std::cout << "in-edges: ";
	  // in_edge iterator ����
	  typename GraphTraits::in_edge_iterator in_i, in_end;
	  for (boost::tie(in_i, in_end) = in_edges(v,g); in_i != in_end; ++in_i) {
		  // �������� ���� in_edge ���� ���
		  e = *in_i;
		  Vertex src = source(e, g), targ = target(e, g);
		  std::cout << "(" << index[src] << "," << index[targ] << ") ";
	  }
	  std::cout << std::endl;

	  // edge ��� �� adjacent vertices ���
	  std::cout << "adjacent vertices: ";
      typename graph_traits<Graph>::adjacency_iterator ai;
	  typename graph_traits<Graph>::adjacency_iterator ai_end;
	  for (boost::tie(ai, ai_end) = adjacent_vertices(v, g); ai != ai_end; ++ai){
		  // �������� ���� adjacent vertex ���
		  std::cout << index[*ai] <<  " ";
	  }
	  std::cout << std::endl;
	}
};

int main(int, char*[]) {

	// Constructing a Graph

	
	// vertex �̸�, ���� ����
	enum {A,B,C,D,E,N};
	const int num_vertices = N;
	const char* name = "ABCDE";
	
	// edge ����, ���� ����
	typedef std::pair<int, int> Edge;
	Edge edge_array[] =
	{ Edge(A,B), Edge(A,D), Edge(C,A), Edge(D,C), Edge(C,E), Edge(B,D), Edge(D,E) };
	const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);
	// �׷��� ����
	Graph g(num_vertices);
	// �׷����� edge �߰�
	for(int i=0; i<num_edges; i++)
		add_edge(edge_array[i].first, edge_array[i].second, g);

	// Accessing the Vertex Set

	// vectex Ÿ�� �̸� ����
	typedef graph_traits<Graph>::vertex_descriptor Vertex;
	IndexMap index = get(vertex_index, g);

	// vertex�� �����Ͽ� ���
	std::cout<<"vertices(g) = ";
	// vertex iterator Ÿ�� ����
	typedef graph_traits<Graph>::vertex_iterator vertex_iter;
	std::pair<vertex_iter, vertex_iter>vp;
	for(vp=vertices(g); vp.first != vp.second; ++vp.first) {
		// �������� ���� vp.first�� value�� �ش��ϴ� vertex�� �̸� ���
		Vertex v = *vp.first;
		std::cout << index[v] <<" ";
	}
	std::cout << std::endl;

	// Accessing the Edge Set

	// edge_iterator Ÿ�� ����
	std::cout << "edges(g) = ";
    graph_traits<Graph>::edge_iterator ei, ei_end;
	// tie �Լ��� ���� ei, ei_end ���ÿ� ����
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
		// source, target �Լ��� ���� ������� �������� ���
        std::cout << "(" << index[source(*ei, g)] 
                  << "," << index[target(*ei, g)] << ") ";
    std::cout << std::endl;

	// functor�� �̿��� for each
	std::for_each(vertices(g).first, vertices(g).second, exercise_vertex<Graph>(g));


	return 0;
}