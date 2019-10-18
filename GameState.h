#ifndef MONOPOLYC_V2_GAMESTATE_H
#define MONOPOLYC_V2_GAMESTATE_H

/* C++ library headers */
#include <cstdint>          /* Better integer types */
#include <iostream>
#include <vector>
/* Project headers */
#include "Board.h"
#include "DiceRoller.h"
#include "Player.h"
#include "Rules.h"


/**
 * TODO - WRITE COMMENTS HERE
 * GOOD EXPLANATION OF WHAT THE CLASS IS FOR
 */
class GameState {
 public:

    /**
     * TODO - WRITE COMMENTS HERE
     */
    GameState(const std::string& rules_file_name, const std::string& board_file_name, const std::string& random_nums_file_name);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    Board& get_board();

    /**
     * get_num_players
     * returns the number of players currently on the board
     * does not count players who have lost
     * parameters: NA
     * return: int
     */
    uint8_t get_num_players();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint8_t get_num_players_left();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    DiceRoller& get_diceRoller();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint8_t get_current_turn();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    std::vector<Player>& get_playersvec();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint8_t get_current_player_id();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void set_players();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    std::string& get_current_player_name();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    Player& get_current_player();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    Rules& get_rules();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    std::string get_player_name_by_id(int i);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint32_t get_player_cash_by_id(int i);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void set_player_cash_by_id(int id, int cash);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void next_player();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void display_gamestate();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    bool is_game_over();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void declare_winner();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    int total_asseet_of_player(int id);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    int set_max_space_len();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    int get_num_players_on(int spaceid);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void deduct_num_of_players_left();

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void rent_update(int space_position);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    void update_Rent(int space_position);

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint8_t num_of_players_left;

 private:
    /* Instance Variables */

    /**
     * TODO - WRITE COMMENTS HERE
     */
    Board  board;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    std::vector<Player> playersvec;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    Rules rule;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    DiceRoller diceRoller;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    unsigned int num_of_players;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint32_t current_turn;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint8_t current_player_id;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    std::string current_player_name;

    /**
     * TODO - WRITE COMMENTS HERE
     */
    uint8_t max_space_len;

    /**
     * TODO - WRITE COMMENTS HERE
     * maximum length of name in all players
     */
    uint16_t max_name_len = 0;

};
#endif //MONOPOLYC_V2_GAMESTATE_H
