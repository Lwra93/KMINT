#pragma once
#include "Map.h"
#include <ctime>
#include <cmath>

Map::Map()
{
	srand(time(NULL));
}

Map::~Map()
{
	for (auto vertex : this->vertexes)
		delete(vertex);

	for (auto edge : this->edges)
		delete(edge);
}

void Map::addVertex(Vertex* v)
{
	this->vertexes.push_back(v);
}

void Map::addEdge(Edge* e)
{
	this->edges.push_back(e);
}

void Map::draw(FWApplication &application)
{

	application.SetColor(Color(246, 246, 246, 255));
	for(auto edge : this->edges)
	{
		int x1 = edge->getVertexes()[0]->getX();
		int x2 = edge->getVertexes()[1]->getX();
		int y1 = edge->getVertexes()[0]->getY();
		int y2 = edge->getVertexes()[1]->getY();
		application.DrawLine(x1, y1, x2, y2);
	}

	application.SetColor(Color(235, 235, 235, 255));
	for (auto vertex : this->vertexes)
		application.DrawCircle(vertex->getX(), vertex->getY(), 5, true);


}

void Map::load()
{
	auto vertex1 = new Vertex(12, 564);
	addVertex(vertex1);
	auto vertex103 = new Vertex(105, 548);
	addVertex(vertex103);
	auto vertex104 = new Vertex(37, 540);
	addVertex(vertex104);
	auto vertex105 = new Vertex(31, 470);
	addVertex(vertex105);
	auto vertex107 = new Vertex(109, 488);
	addVertex(vertex107);
	auto vertex108 = new Vertex(60, 420);
	addVertex(vertex108);
	auto vertex109 = new Vertex(24, 424);
	addVertex(vertex109);
	auto vertex110 = new Vertex(121, 417);
	addVertex(vertex110);
	auto vertex111 = new Vertex(153, 456);
	addVertex(vertex111);
	auto vertex112 = new Vertex(150, 506);
	addVertex(vertex112);
	auto vertex113 = new Vertex(151, 550);
	addVertex(vertex113);
	auto vertex114 = new Vertex(205, 528);
	addVertex(vertex114);
	auto vertex115 = new Vertex(44, 376);
	addVertex(vertex115);
	auto vertex116 = new Vertex(172, 400);
	addVertex(vertex116);
	auto vertex117 = new Vertex(79, 466);
	addVertex(vertex117);
	auto vertex118 = new Vertex(105, 370);
	addVertex(vertex118);
	auto vertex119 = new Vertex(104, 291);
	addVertex(vertex119);
	auto vertex120 = new Vertex(120, 258);
	addVertex(vertex120);
	auto vertex121 = new Vertex(90, 244);
	addVertex(vertex121);
	auto vertex122 = new Vertex(98, 212);
	addVertex(vertex122);
	auto vertex123 = new Vertex(151, 268);
	addVertex(vertex123);
	auto vertex124 = new Vertex(138, 226);
	addVertex(vertex124);
	auto vertex125 = new Vertex(112, 186);
	addVertex(vertex125);
	auto vertex126 = new Vertex(164, 200);
	addVertex(vertex126);
	auto vertex127 = new Vertex(195, 171);
	addVertex(vertex127);
	auto vertex128 = new Vertex(136, 144);
	addVertex(vertex128);
	auto vertex129 = new Vertex(164, 135);
	addVertex(vertex129);
	auto vertex130 = new Vertex(166, 98);
	addVertex(vertex130);
	auto vertex131 = new Vertex(141, 58);
	addVertex(vertex131);
	auto vertex132 = new Vertex(90, 96);
	addVertex(vertex132);
	auto vertex133 = new Vertex(54, 156);
	addVertex(vertex133);
	auto vertex134 = new Vertex(55, 211);
	addVertex(vertex134);
	auto vertex135 = new Vertex(57, 268);
	addVertex(vertex135);
	auto vertex136 = new Vertex(180, 331);
	addVertex(vertex136);
	auto vertex137 = new Vertex(212, 354);
	addVertex(vertex137);
	auto vertex138 = new Vertex(138, 332);
	addVertex(vertex138);
	auto vertex139 = new Vertex(129, 294);
	addVertex(vertex139);
	auto vertex140 = new Vertex(176, 292);
	addVertex(vertex140);
	auto vertex141 = new Vertex(188, 267);
	addVertex(vertex141);
	auto vertex142 = new Vertex(181, 249);
	addVertex(vertex142);
	auto vertex143 = new Vertex(213, 223);
	addVertex(vertex143);
	auto vertex144 = new Vertex(291, 283);
	addVertex(vertex144);
	auto vertex145 = new Vertex(259, 313);
	addVertex(vertex145);
	auto vertex146 = new Vertex(325, 357);
	addVertex(vertex146);
	auto vertex147 = new Vertex(242, 379);
	addVertex(vertex147);
	auto vertex148 = new Vertex(231, 428);
	addVertex(vertex148);
	auto vertex149 = new Vertex(195, 439);
	addVertex(vertex149);
	auto vertex150 = new Vertex(236, 528);
	addVertex(vertex150);
	auto vertex151 = new Vertex(252, 469);
	addVertex(vertex151);
	auto vertex152 = new Vertex(285, 469);
	addVertex(vertex152);
	auto vertex153 = new Vertex(292, 450);
	addVertex(vertex153);
	auto vertex154 = new Vertex(303, 415);
	addVertex(vertex154);
	auto vertex155 = new Vertex(268, 413);
	addVertex(vertex155);
	auto vertex156 = new Vertex(270, 384);
	addVertex(vertex156);
	auto vertex157 = new Vertex(345, 387);
	addVertex(vertex157);
	auto vertex158 = new Vertex(349, 430);
	addVertex(vertex158);
	auto vertex159 = new Vertex(400, 452);
	addVertex(vertex159);
	auto vertex160 = new Vertex(313, 488);
	addVertex(vertex160);
	auto vertex161 = new Vertex(308, 528);
	addVertex(vertex161);
	auto vertex162 = new Vertex(374, 472);
	addVertex(vertex162);
	auto vertex163 = new Vertex(423, 481);
	addVertex(vertex163);
	auto vertex164 = new Vertex(434, 519);
	addVertex(vertex164);
	auto vertex165 = new Vertex(493, 480);
	addVertex(vertex165);
	auto vertex166 = new Vertex(529, 427);
	addVertex(vertex166);
	auto vertex167 = new Vertex(526, 366);
	addVertex(vertex167);
	auto vertex168 = new Vertex(491, 367);
	addVertex(vertex168);
	auto vertex169 = new Vertex(478, 386);
	addVertex(vertex169);
	auto vertex170 = new Vertex(452, 340);
	addVertex(vertex170);
	auto vertex171 = new Vertex(417, 369);
	addVertex(vertex171);
	auto vertex172 = new Vertex(390, 404);
	addVertex(vertex172);
	auto vertex184 = new Vertex(171, 481);
	addVertex(vertex184);
	auto vertex200 = new Vertex(84, 402);
	addVertex(vertex200);
	auto vertex231 = new Vertex(214, 55);
	addVertex(vertex231);
	auto vertex232 = new Vertex(265, 56);
	addVertex(vertex232);
	auto vertex233 = new Vertex(336, 54);
	addVertex(vertex233);
	auto vertex234 = new Vertex(369, 54);
	addVertex(vertex234);
	auto vertex235 = new Vertex(376, 135);
	addVertex(vertex235);
	auto vertex236 = new Vertex(404, 171);
	addVertex(vertex236);
	auto vertex237 = new Vertex(331, 190);
	addVertex(vertex237);
	auto vertex238 = new Vertex(369, 210);
	addVertex(vertex238);
	auto vertex239 = new Vertex(343, 145);
	addVertex(vertex239);
	auto vertex240 = new Vertex(322, 103);
	addVertex(vertex240);
	auto vertex241 = new Vertex(294, 104);
	addVertex(vertex241);
	auto vertex242 = new Vertex(285, 134);
	addVertex(vertex242);
	auto vertex243 = new Vertex(278, 152);
	addVertex(vertex243);
	auto vertex244 = new Vertex(231, 142);
	addVertex(vertex244);
	auto vertex245 = new Vertex(187, 127);
	addVertex(vertex245);
	auto vertex248 = new Vertex(236, 183);
	addVertex(vertex248);
	auto vertex249 = new Vertex(253, 204);
	addVertex(vertex249);
	auto vertex255 = new Vertex(268, 84);
	addVertex(vertex255);
	auto vertex262 = new Vertex(220, 102);
	addVertex(vertex262);
	auto vertex266 = new Vertex(340, 85);
	addVertex(vertex266);
	auto vertex277 = new Vertex(313, 259);
	addVertex(vertex277);
	auto vertex280 = new Vertex(297, 184);
	addVertex(vertex280);
	auto vertex281 = new Vertex(313, 176);
	addVertex(vertex281);
	auto vertex282 = new Vertex(307, 206);
	addVertex(vertex282);
	auto vertex287 = new Vertex(309, 147);
	addVertex(vertex287);
	auto vertex304 = new Vertex(82, 201);
	addVertex(vertex304);
	auto vertex309 = new Vertex(268, 358);
	addVertex(vertex309);
	auto vertex311 = new Vertex(312, 375);
	addVertex(vertex311);
	auto vertex330 = new Vertex(355, 339);
	addVertex(vertex330);
	auto vertex343 = new Vertex(438, 313);
	addVertex(vertex343);
	auto vertex345 = new Vertex(490, 324);
	addVertex(vertex345);
	auto vertex348 = new Vertex(462, 303);
	addVertex(vertex348);
	auto vertex351 = new Vertex(468, 282);
	addVertex(vertex351);
	auto vertex352 = new Vertex(394, 232);
	addVertex(vertex352);
	auto vertex353 = new Vertex(429, 229);
	addVertex(vertex353);
	auto vertex354 = new Vertex(400, 272);
	addVertex(vertex354);
	auto vertex355 = new Vertex(397, 309);
	addVertex(vertex355);
	auto vertex356 = new Vertex(386, 341);
	addVertex(vertex356);
	auto vertex360 = new Vertex(384, 297);
	addVertex(vertex360);
	auto vertex364 = new Vertex(447, 273);
	addVertex(vertex364);
	auto vertex371 = new Vertex(524, 298);
	addVertex(vertex371);
	auto vertex372 = new Vertex(522, 199);
	addVertex(vertex372);
	auto vertex373 = new Vertex(468, 202);
	addVertex(vertex373);
	auto vertex374 = new Vertex(465, 228);
	addVertex(vertex374);
	auto vertex375 = new Vertex(475, 248);
	addVertex(vertex375);
	auto vertex383 = new Vertex(453, 145);
	addVertex(vertex383);
	auto vertex384 = new Vertex(418, 118);
	addVertex(vertex384);
	auto vertex385 = new Vertex(417, 31);
	addVertex(vertex385);
	auto vertex386 = new Vertex(420, 67);
	addVertex(vertex386);
	auto vertex387 = new Vertex(398, 94);
	addVertex(vertex387);
	auto vertex388 = new Vertex(451, 88);
	addVertex(vertex388);
	auto vertex389 = new Vertex(481, 110);
	addVertex(vertex389);
	auto vertex390 = new Vertex(476, 168);
	addVertex(vertex390);
	auto vertex391 = new Vertex(500, 151);
	addVertex(vertex391);
	auto vertex392 = new Vertex(546, 146);
	addVertex(vertex392);
	auto vertex393 = new Vertex(541, 103);
	addVertex(vertex393);
	auto vertex394 = new Vertex(531, 45);
	addVertex(vertex394);
	auto vertex395 = new Vertex(550, 24);
	addVertex(vertex395);
	auto vertex396 = new Vertex(470, 42);
	addVertex(vertex396);
	auto vertex432 = new Vertex(440, 424);
	addVertex(vertex432);
	addEdge(new Edge(vertex1, vertex104, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex103, vertex107, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex117, vertex107, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex117, vertex105, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex105, vertex104, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex104, vertex103, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex103, vertex113, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex113, vertex112, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex112, vertex107, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex107, vertex111, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex111, vertex184, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex184, vertex112, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex112, vertex114, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex184, vertex114, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex114, vertex113, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex117, vertex110, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex108, vertex117, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex110, vertex116, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex116, vertex111, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex110, vertex111, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex105, vertex109, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex109, vertex108, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex108, vertex115, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex115, vertex109, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex108, vertex200, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex200, vertex110, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex115, vertex200, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex114, vertex149, EdgeWeight::LANE));
	addEdge(new Edge(vertex149, vertex116, EdgeWeight::LANE));
	addEdge(new Edge(vertex116, vertex118, EdgeWeight::LANE));
	addEdge(new Edge(vertex118, vertex115, EdgeWeight::LANE));
	addEdge(new Edge(vertex114, vertex150, EdgeWeight::LANE));
	addEdge(new Edge(vertex150, vertex151, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex151, vertex148, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex148, vertex149, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex148, vertex147, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex147, vertex137, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex137, vertex116, EdgeWeight::LANE));
	addEdge(new Edge(vertex137, vertex136, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex136, vertex140, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex140, vertex141, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex141, vertex145, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex145, vertex137, EdgeWeight::LANE));
	addEdge(new Edge(vertex136, vertex138, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex138, vertex139, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex139, vertex140, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex139, vertex119, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex119, vertex118, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex119, vertex135, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex135, vertex115, EdgeWeight::LANE));
	addEdge(new Edge(vertex135, vertex134, EdgeWeight::LANE));
	addEdge(new Edge(vertex134, vertex133, EdgeWeight::LANE));
	addEdge(new Edge(vertex133, vertex132, EdgeWeight::LANE));
	addEdge(new Edge(vertex132, vertex131, EdgeWeight::LANE));
	addEdge(new Edge(vertex245, vertex244, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex244, vertex242, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex244, vertex248, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex248, vertex249, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex242, vertex243, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex242, vertex241, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex241, vertex240, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex241, vertex255, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex255, vertex232, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex232, vertex231, EdgeWeight::LANE));
	addEdge(new Edge(vertex231, vertex131, EdgeWeight::LANE));
	addEdge(new Edge(vertex131, vertex130, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex130, vertex262, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex262, vertex255, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex233, vertex232, EdgeWeight::LANE));
	addEdge(new Edge(vertex240, vertex266, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex266, vertex233, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex233, vertex234, EdgeWeight::LANE));
	addEdge(new Edge(vertex234, vertex235, EdgeWeight::LANE));
	addEdge(new Edge(vertex235, vertex239, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex239, vertex240, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex239, vertex237, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex237, vertex238, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex238, vertex236, EdgeWeight::LANE));
	addEdge(new Edge(vertex236, vertex235, EdgeWeight::LANE));
	addEdge(new Edge(vertex277, vertex238, EdgeWeight::LANE));
	addEdge(new Edge(vertex277, vertex249, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex282, vertex280, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex280, vertex249, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex280, vertex281, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex287, vertex281, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex287, vertex242, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex127, vertex126, EdgeWeight::WATER));
	addEdge(new Edge(vertex126, vertex124, EdgeWeight::WATER));
	addEdge(new Edge(vertex126, vertex128, EdgeWeight::WATER));
	addEdge(new Edge(vertex128, vertex132, EdgeWeight::WATER));
	addEdge(new Edge(vertex143, vertex126, EdgeWeight::WATER));
	addEdge(new Edge(vertex143, vertex144, EdgeWeight::WATER));
	addEdge(new Edge(vertex144, vertex277, EdgeWeight::LANE));
	addEdge(new Edge(vertex144, vertex145, EdgeWeight::LANE));
	addEdge(new Edge(vertex143, vertex142, EdgeWeight::WATER));
	addEdge(new Edge(vertex142, vertex141, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex119, vertex120, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex120, vertex123, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex120, vertex121, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex121, vertex122, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex134, vertex304, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex124, vertex125, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex123, vertex124, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex146, vertex145, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex309, vertex156, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex146, vertex311, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex311, vertex156, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex156, vertex155, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex155, vertex153, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex153, vertex154, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex153, vertex152, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex152, vertex151, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex152, vertex160, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex160, vertex161, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex161, vertex150, EdgeWeight::LANE));
	addEdge(new Edge(vertex161, vertex164, EdgeWeight::LANE));
	addEdge(new Edge(vertex164, vertex163, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex163, vertex162, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex162, vertex160, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex159, vertex158, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex158, vertex153, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex158, vertex157, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex157, vertex311, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex330, vertex146, EdgeWeight::WATER));
	addEdge(new Edge(vertex330, vertex144, EdgeWeight::WATER));
	addEdge(new Edge(vertex171, vertex172, EdgeWeight::WATER));
	addEdge(new Edge(vertex165, vertex164, EdgeWeight::LANE));
	addEdge(new Edge(vertex165, vertex166, EdgeWeight::LANE));
	addEdge(new Edge(vertex166, vertex167, EdgeWeight::LANE));
	addEdge(new Edge(vertex167, vertex168, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex168, vertex169, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex169, vertex170, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex171, vertex170, EdgeWeight::WATER));
	addEdge(new Edge(vertex343, vertex170, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex345, vertex168, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex348, vertex345, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex348, vertex343, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex330, vertex356, EdgeWeight::WATER));
	addEdge(new Edge(vertex356, vertex171, EdgeWeight::WATER));
	addEdge(new Edge(vertex356, vertex355, EdgeWeight::WATER));
	addEdge(new Edge(vertex355, vertex360, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex360, vertex277, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex360, vertex354, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex364, vertex354, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex354, vertex352, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex352, vertex353, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex353, vertex364, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex364, vertex351, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex348, vertex351, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex375, vertex351, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex375, vertex374, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex374, vertex373, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex373, vertex372, EdgeWeight::LANE));
	addEdge(new Edge(vertex372, vertex371, EdgeWeight::LANE));
	addEdge(new Edge(vertex371, vertex167, EdgeWeight::LANE));
	addEdge(new Edge(vertex373, vertex236, EdgeWeight::LANE));
	addEdge(new Edge(vertex395, vertex394, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex394, vertex396, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex396, vertex385, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex385, vertex386, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex385, vertex234, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex234, vertex386, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex386, vertex387, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex387, vertex384, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex384, vertex388, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex388, vertex386, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex388, vertex396, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex388, vertex389, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex389, vertex383, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex384, vertex383, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex383, vertex236, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex236, vertex384, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex383, vertex390, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex390, vertex391, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex391, vertex389, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex389, vertex393, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex393, vertex392, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex392, vertex391, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex391, vertex372, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex372, vertex392, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex393, vertex394, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex352, vertex238, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex129, vertex128, EdgeWeight::WATER));
	addEdge(new Edge(vertex129, vertex130, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex245, vertex129, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex245, vertex130, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex249, vertex143, EdgeWeight::WATER));
	addEdge(new Edge(vertex122, vertex304, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex125, vertex304, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex159, vertex163, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex432, vertex171, EdgeWeight::WATER));
	addEdge(new Edge(vertex432, vertex159, EdgeWeight::NORMAL));
	addEdge(new Edge(vertex432, vertex165, EdgeWeight::WATER));
	addEdge(new Edge(vertex351, vertex371, EdgeWeight::NORMAL));

	addConnectionsVertexes();
}

Vertex* Map::randomVertex(Vertex* current) const
{

	auto loc = current;

	while(loc == current)
	{
		
		auto index = rand() % vertexes.size();
		loc = vertexes[index];
	}

	

	return loc;

}

Vertex* Map::getVertex(int location) const
{
	return vertexes.at(location);
}

void Map::resetCosts()
{
	for (auto vertex : vertexes)
		vertex->resetCost();
}

vector<Vertex*> Map::getVertexes()
{
	return vertexes;
}

void Map::addConnectionsVertexes()
{
	for(auto v : vertexes)
	{
		auto tempEdges = v->getEdges();
		for(auto e : v->getEdges())
		{
			auto tempNeighbours = e->getVertexes();

			for (auto temp : e->getVertexes())
			{
				
				if (temp->getX() != v->getX() || temp->getY() != v->getY())
				{
					v->connections.push_back(temp);
				}
			}
		}
		
	}


	
}
