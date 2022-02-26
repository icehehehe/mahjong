﻿#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Table.h"
#include <array>
std::array<int, 4> 东风局(std::array<Agent*, 4> agents, std::stringstream&);

std::array<int, 4> 南风局(std::array<Agent*, 4> agents, std::stringstream&);

std::array<int, 4> FullGame(Wind, std::array<Agent*, 4> agents, std::stringstream&);

class PaipuReplayer
{
public:
	Table table;
	PaipuReplayer() = default;
	void init(std::vector<int> yama, std::vector<int> init_scores, int 立直棒, int 本场, int 场风, int 亲家);
	std::vector<SelfAction> get_self_actions() const;
	std::vector<ResponseAction> get_response_actions() const;
	
	bool make_selection(int selection);
	bool make_selection_from_action(BaseAction action, std::vector<int> correspond_tiles);
	int get_selection_from_action(BaseAction action, std::vector<int> correspond_tiles);
	int get_phase() const;
	Result get_result() const;	
	~PaipuReplayer() {  } 
};

#endif