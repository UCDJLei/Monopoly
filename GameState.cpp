#include "GameState.h"

GameState::GameState(const std::string& rules_file_name,
                     const std::string& board_file_name,
                     const std::string& random_nums_file_name)
        :board(board_file_name),
         rule(rules_file_name),
         diceRoller(random_nums_file_name)
{
    current_turn        = 0;
    current_player_id   = 0;
    max_space_len       = set_max_space_len();
}


void GameState::set_players()
{
    std::cout << "Enter how many players will be playing: ";
    int temp_num_players = 0;
    while (temp_num_players <= 0) {
        std::cin >> temp_num_players;
        if (temp_num_players <= 0)
            std::cout << "Please enter a positive number of players.\n";
    }
    num_of_players = (unsigned int) temp_num_players;
    std::string input_name = "NO NAME";

    for (unsigned int i = 0; i < num_of_players; i ++) {
        std::cout << "Enter the name of player " << (i + 1) << ": ";
        std::cin >> input_name;
        max_name_len = std::max(input_name.length(), max_name_len);
        //set all the pointers of space to the 0 space.
        Player player (input_name, i);
        player.position = 0;
        player.cash = get_rules().get_starting_cash();
        playersvec.push_back(player);
    }
    num_of_players_left = num_of_players;

}


void GameState::next_player()
{
    do {
        current_player_id = (current_player_id + 1) % num_of_players;
        current_turn++;
    } while (!playersvec[current_player_id].get_in_game());
}


void GameState::display_gamestate()
{
    std::cout << "Space Number | " << "Space Name";

    for (uint8_t i = 0; i < max_space_len - 10; i++)
        std::cout << " ";
    std::cout <<" | Owner ";
    for(uint8_t i = 0 ; i < max_name_len - 5; i++)
        std::cout << " ";
    std::cout << "| Players" <<std::endl;
    /* Start print out the state information from space 0 */
    for (int j = 0; j < get_board().get_num_of_spaces() ; j ++) {
        std::cout << j;
        int temp_len = static_cast<int>(std::to_string(j).length());

        for (int i = 0 ; i < (13- temp_len); i ++)
            std::cout << " ";
        std::cout << "| ";
        get_board().get_spacevec()[j].print_space_name();
        std::string temp_string = board.get_spacevec()[j].get_space_name();
        for (unsigned int k = 0; k < (max_space_len - (get_board().get_spacevec()[j].get_space_name().length())) ; k++)
            std::cout << " ";
        std::cout << " | ";

        /* Owner column */
        int temp_ownerid = get_board().get_spacevec()[j].get_ownerId();
        if (temp_ownerid == -1 || temp_ownerid == -2) {
            std::cout << "None";
            for (uint16_t i = 0; i < (max_name_len - 4); i++)
                std::cout << " ";
        } else {
            std::cout << get_playersvec()[temp_ownerid].get_name();
            /* Fill up the space for owner */
            for (uint16_t i = 0; i < max_name_len - static_cast<int>((get_playersvec()[temp_ownerid].get_name()).length()); i++)
                std::cout << " ";
        }

        /* Print out players' names, who land on the property */
        std::cout << " | ";
        int player_on_land = 0;
        for (int k = 0; k < num_of_players; k++) {
            if (get_playersvec()[k].get_position() == j && get_playersvec()[k].get_in_the_game()) {
                player_on_land++;
            }
        }

        int k = 0;
        int g = 0;
        for ( k = 0; k < num_of_players; k++) {
            if(g < player_on_land - 1) {
                if (get_playersvec()[k].get_position() == j &&  get_playersvec()[k].get_in_the_game()) {
                    std::cout << "[" << get_playersvec()[k].get_name() << " : $" << get_playersvec()[k].get_cash() << "]";
                    std::cout << ", ";
                    g++;
                }
            }
                /* distinguish the last player on that spot */
             else  {
                if (get_playersvec()[k].get_position() == j  && get_playersvec()[k].get_in_the_game()) {
                    std::cout << "[" << get_playersvec()[k].get_name() << " : $" << get_playersvec()[k].get_cash() << "]";
                    g++;
                }
            }

            }
        std::cout << std::endl;
    }
}


bool GameState::is_game_over()
{

    if (num_of_players_left <= get_rules().get_number_of_players_left_to_end_game() || current_turn >= get_rules().get_turn_limit() || num_of_players_left ==1)
        return true;
    else
        return false;
}


void GameState::declare_winner()
{
    int max_asset = 0;

    for (int i = 0; i < num_of_players; i++) {
        if (total_asseet_of_player(i) >= max_asset && get_playersvec()[i].get_in_the_game()) {
            max_asset = total_asseet_of_player(i);
        }
    }
    std::cout << "The winners are" << std::endl;

    for (int i = 0; i < num_of_players; i++) {
        if (total_asseet_of_player(i) == max_asset && get_playersvec()[i].get_in_the_game()) {
            std::cout << get_playersvec()[i].get_name()<<std::endl;

        }
    }
}


int GameState::total_asseet_of_player(int id)
{
    int asset_temp = 0;
    for (unsigned int i = 0 ; i < board.num_of_spaces; i++) {
        if(get_board().get_spacevec()[i].get_ownerId() == id) {
            asset_temp += get_board().get_spacevec()[i].get_proptr()->get_cost_to_purchase();
        }
    }
    asset_temp += get_playersvec()[id].get_cash();
    return asset_temp;
}


int GameState::set_max_space_len()
{
    int temp_space_name_len = 10;
    for (int i = 0; i < (board.num_of_spaces); ++i) {
        if (temp_space_name_len <= static_cast<int>(board.get_spacevec()[i].get_space_name().length())) {
            temp_space_name_len = static_cast<int>(board.get_spacevec()[i].get_space_name().size());
        }
    }
    return temp_space_name_len;
}


int GameState::get_num_players_on(int spaceid)
{
    int count = 0;
    for (uint8_t i = 0; i < num_of_players; i ++){
        if (playersvec[i].get_position() == spaceid){
            count ++;
        }
    }
    return count;
}


void GameState::deduct_num_of_players_left()
{
    num_of_players_left--;
}


void GameState::update_Rent(int space_position)
{
    get_board().get_spacevec()[space_position].get_proptr()->set_update_Rent(get_rules().get_salary_multiplier_for_landing_on_go());
}


/* Simple getters and setters, condensed for clarity */
Board&      GameState::get_board()              { return board;                }
uint8_t     GameState::get_num_players()        { return num_of_players;       }
uint8_t     GameState::get_num_players_left()   { return num_of_players_left;  }
DiceRoller& GameState::get_diceRoller()         { return diceRoller;           }
uint8_t     GameState::get_current_turn()       { return current_turn;         }
std::vector<Player>& GameState::get_playersvec() { return playersvec; }
uint8_t     GameState::get_current_player_id()  { return current_player_id;    }
Rules& GameState::get_rules()                   { return rule;                 }
std::string GameState::get_player_name_by_id(int i)
{
    return get_playersvec()[i].get_name();
}
uint32_t GameState::get_player_cash_by_id(int i)
{
    return playersvec[i].cash;
}
void GameState::set_player_cash_by_id(int id, int cash)
{
     playersvec[id].cash += cash;
}
Player& GameState::get_current_player()         { return get_playersvec()[get_current_player_id()]; }
std::string& GameState::get_current_player_name() { return get_current_player().get_name(); }
/* end getters and setters */
