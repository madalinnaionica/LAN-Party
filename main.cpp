//Ionica Madalina Cristina 322AA
#include <iostream>
#include <fstream>
#include "player.hpp"
#include "team.hpp"
#include "list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "game.hpp"
#include <algorithm>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void read_tasks(string *tasks_to_solve, string file_name) //citirea fisierului de cerinte
{
    ifstream tasks_file(file_name);

    if (tasks_file.is_open())
    {
        getline(tasks_file, *tasks_to_solve);
        tasks_file.close();
    }
    else
        cout << "Unable to open file: " << file_name;
}

void read_teams(string file_name, List *list, int *number_of_teams) //functie pentru citirea echipelor din fisier
{
    ifstream teams_file(file_name);
    string line;

    if (teams_file.is_open())
    {
        getline(teams_file, line);
        *number_of_teams = stoi(line);

        for (int i = 0; i < *number_of_teams; i++)
        {
            int number_of_players;

            string team_name;

            float score = 0.00;

            getline(teams_file, line); // se incepe citirea informatiilor despre echipe

            number_of_players = stoi(line.substr(0, line.find(" ")));

            team_name = line.substr(line.find(" ") + 1, line.length());

            if (team_name.back() == ' ') // verific daca numele echipei are un ultim spatiu
            {
                team_name = team_name.substr(0, team_name.length() - 1); // citesc numele echipei tinand cont de criteriul anterior pentru cazurile particulare
            }

            Player *players = new Player[number_of_players];

            for (int j = 0; j < number_of_players; j++) // se incepe citirea informatiilor despre jucatori
            {
                string name, first_name, second_name;
                int points;

                getline(teams_file, line);

                name = line.substr(0, line.find_last_of(" "));
                first_name = name.substr(0, name.find(" "));
                second_name = name.substr(name.find(" ") + 1, name.length());
                points = stoi(line.substr(line.find_last_of(" ") + 1, line.length()));

                Player player(first_name, second_name, points);
                players[j] = player;
                score += points; //calcularea scorului
            }

            Team team(team_name, number_of_players, score / number_of_players, players);

            delete[] players;

            list->add_node(team);

            // echipele sunt separate printr-o linie goala
            getline(teams_file, line);
        }
        teams_file.close();
    }
    else
        cout << "Unable to open file: " << file_name;
}

int pwr(int n) // functia de calcul a puterii 2, ce returneaza cel mai mare numar de forma 2^n, mai mic decat numarul dat ca parametru
{
    int p = 0;
    while ((n / 2) >= 1)
    {
        n = n / 2;
        p++;
    }
    for (int i = 0; i < p; i++)
    {
        n = n * 2;
    }
    return n;
}

void delete_teams(List *teams, int nr_teams) // functie pentru stergerea echipelor cu cel mai mic punctaj
{

    int nr_teams_temp = pwr(nr_teams);                 // am creat un numar de echipe temporar egal cel mai mai mare numar de forma 2^n mai mic decat numarul de echipe
    int nr_teams_to_remove = nr_teams - nr_teams_temp; //scadem din numarul de echipe, echipele memorate anterior pentru a afla cate echipe trebuie sa eliminam

    for (int i = 0; i < nr_teams_to_remove; i++)
    {
        Team team_removed = teams->lowest_score();
        teams->delete_node(team_removed);
    }
}

void create_games(List *teams, Queue *queue_games, Stack *stack_winners, Stack *stack_loosers) // functie pentru crearea meciurilor dintre echipe
{

    Node *temp = teams->get_head();
    while (temp->next->next != NULL) // iterez prin lista din 2 in 2
    {

        Game game(temp->data, temp->next->data);
        queue_games->enQueue(game);
        stack_winners->Push(game.get_winner());
        stack_loosers->Push(game.get_looser());

        if (temp->next->next->next->next == NULL && temp->next->next->next != NULL)
        {
            Game game_final(temp->next->next->data, temp->next->next->next->data); //in cazul in care ajung la formarea penultimei echipe, voi crea si ultima echipa
            queue_games->enQueue(game_final);
            stack_winners->Push(game_final.get_winner());
            stack_loosers->Push(game_final.get_looser());
        }

        temp = temp->next->next;
    }
}

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        cout << "Numar de parametrii incorect! Apelul corect este: ./lanParty c.in d.in r.out ";

        return 0;
    }

    string tasks_to_solve;
    List list_of_teams;
    Queue queue_of_teams;
    Stack stack_winners;
    Stack stack_loosers;

    int nr_teams;

    read_tasks(&tasks_to_solve, argv[1]);

    read_teams(argv[2], &list_of_teams, &nr_teams);

    ofstream output_file;

    if (tasks_to_solve.compare("1 0 0 0 0") == 0)
    {
        output_file.open(argv[3], ios::trunc);
        // "============================ TASK 1 ============================\n";
        output_file << list_of_teams.print_teams_names();
    }
    if (tasks_to_solve.compare("1 1 0 0 0") == 0)
    {
        output_file.open(argv[3], ios::trunc);
        // "============================ TASK 2 ============================\n";
        delete_teams(&list_of_teams, nr_teams);
        output_file << list_of_teams.print_teams_names();
    }
    if (tasks_to_solve.compare("1 1 1 0 0") == 0)
    {
        output_file.open(argv[3]);
        // "============================ TASK 3 ============================\n";

        delete_teams(&list_of_teams, nr_teams);

        int nr_rounds = log2(pwr(nr_teams));

        output_file << list_of_teams.print_teams_names();
        output_file << "\n--- ROUND NO:1\n";
        create_games(&list_of_teams, &queue_of_teams, &stack_winners, &stack_loosers); //crearea meciurilor pentru runda 1
        output_file << queue_of_teams.display_queue();
        output_file << "\nWINNERS OF ROUND NO:1\n";
        output_file << stack_winners.display_stack();

        for (int j = 2; j <= nr_rounds; j++) // am gasit asemanarea de creare a meciurilor urmatoare, de la meciul numarul 2 si le-am creat folosind un for
        {
            int matches_played = pwr(nr_teams) / pow(2, j - 1); // determinam cate meciuri sunt de jucat ajutandu-ne de functia pwr si ghidandu-ne dupa numarul de echipe

            for (int i = 0; i < matches_played; i++)
            {
                stack_loosers.Pop(); //iterez prin stiva de pierzatori si sterg toate echipele din ea
                queue_of_teams.deQueue();
            }

            for (int i = 0; i < matches_played; i += 2)
            {
                Team team1 = stack_winners.get_link()->data; //cu castigatorii din stiva de castigatori vom forma noi gameuri
                stack_winners.Pop();
                Team team2 = stack_winners.get_link()->data;
                Game game(team1, team2);
                stack_winners.Pop();
                queue_of_teams.enQueue(game);
            }
            for (int i = 0; i < matches_played / 2; i++)
            {
                Game game_temp = queue_of_teams.get_front()->data;
                queue_of_teams.deQueue();
                stack_winners.Push(game_temp.get_winner());
                stack_loosers.Push(game_temp.get_looser());
                queue_of_teams.enQueue(game_temp);
            }

            output_file << "\n--- ROUND NO:" << j << "\n";
            output_file << queue_of_teams.display_queue();
            output_file << "\nWINNERS OF ROUND NO:" << j << "\n";
            output_file << stack_winners.display_stack();
        }
    }

    output_file.close();

    return 0;
}
