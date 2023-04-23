#include <stdio.h>

int team1_score = 0, team2_score = 0, wickets1 = 0, wickets2 = 0, overs = 0, balls = 0;
    int current_team = 1;

int main() {
    
    printf("\t\tCRICKET SCOREBOARD\n\n");
    int i=0;
    while(i++<2){
    while (overs < 20) {  // Assuming a 20-over match
        // Print the current scores and wickets
        printf("Team %d: %d/%d\tTeam %d: %d/%d\n", 1, team1_score, wickets1, 2, team2_score, wickets2);

        // Get the number of runs scored in the current ball
        int runs;
        printf("Enter the number of runs scored in ball %d.%d: ", overs, balls+1);
        scanf("%d", &runs);

        // Update the scores and wickets
        if (runs == 0 || runs == 1 || runs == 2 || runs == 3) {
            if (current_team == 1) {
                team1_score += runs;
            } else {
                team2_score += runs;
            }
        } else if (runs == 4 || runs == 6) {
            if (current_team == 1) {
                team1_score += runs;
            } else {
                team2_score += runs;
            }
        } else if (runs == 5) {
            printf("Invalid run: 5 runs cannot be scored in a single ball.\n");
            continue;
        } else {
            // Out!
            printf("OUT!\n");
            if(current_team==1){
                wickets1++;
                if (wickets1 == 10) {
                printf("All out!\n");
                break;
            }
            }else{
                if (wickets2 == 10) {
                printf("All out!\n");
                break;
            }
                wickets2++;
            }
            if (wickets1 == 10 || wickets2 == 10) {
                printf("All out!\n");
                break;
            }
        }

        // Update the overs and balls
        balls++;
        if (balls == 6) {
            overs++;
            balls = 0;
        }
        if(team2_score > team1_score){
            break;
        }
    }
    overs =0;
    balls = 0;
  current_team = 3 - current_team;  // Switch the batting team
}

    // Print the final scores
    printf("\nFinal scores:\n");
    printf("Team %d: %d/%d\nTeam %d: %d/%d\n", 1, team1_score, wickets1, 2, team2_score, wickets2);
    
    if(team2_score>team1_score){
        printf("\n Team 2 wins");
    }else{
        printf("\n Team 1 wins");
    }

    return 0;
}

