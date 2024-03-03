/** @file song_analyzer.c
 *  @brief A pipes & filters program that uses conditionals, loops, and string processing tools in C to process song
 *  data and printing it in a different format.
 *  @author Felipe R.
 *  @author Hausi M.
 *  @author Angadh S.
 *  @author Juan G.
 *  @author Ali S-G.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief The maximum line length.
 *
 */
#define MAX_LINE_LEN 132

/**
 * Function: main
 * --------------
 * @brief The main function and entry point of the program.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The list of arguments passed to the program.
 * @return int 0: No errors; 1: Errors produced.
 *
 */

typedef struct
{
    char track_name[100];
    char artist_name[100];
    int artist_count;
    int released_year;
    int in_spotify_playlists;
    int streams;
    char key[10];
    char mode[10];
} Song;

// function definitions
void processFile(char *filename, char *q);    // opens file, sends lines to be processed
void processLine(char *line, char *question); // process lines and checks conditions of question
Song parseLine(char *line);                   // parses each line to get each song fields
void output(Song song);                       // outputs the correctly formatted list of songs

int main(int argc, char *argv[])
{

    char *arguments[argc]; // Declare an array to store arguments found after "="
    int num_arguments = 0; // Keep track of the number of arguments found

    FILE *outputFile = fopen("output.csv", "w"); // open the output file
    fprintf(outputFile, "Artist(s),Song\n");     // write the header line
    fclose(outputFile);                          // close the file for now

    // Iterate through each argument
    for (int i = 1; i < argc; i++)
    {
        // Tokenize the argument using "="
        char *token = strtok(argv[i], "=");

        // Find the token just after "="
        while (token != NULL)
        {
            arguments[num_arguments] = strtok(NULL, "=");
            num_arguments++; // Increment num args
            break;           // Exit the loop after finding a token
        }
    }

    // arguments at 0 is question number and arguments at 1 is file name

    char *fileName = arguments[1];
    char *question = arguments[0];

    processFile(fileName, question); // process files in other methods
}

// Function to read and process the file
void processFile(char *filename, char *question)
{
    FILE *file = fopen(filename, "r"); // open the input file

    char line[MAX_LINE_LEN];
    // Read and discard the header line
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL)
    {
        processLine(line, question);
    }

    // close the file when done reading
    fclose(file);
}

void processLine(char *line, char *question)
{
    Song song = parseLine(line);

    // switch based on what questions are asked
    switch (atoi(question))
    {
    case 1:
        if (song.released_year < 2020 && strcmp(song.artist_name, "Rae Spoon") == 0)
        {
            output(song);
        }
        break;
    case 2:
        if (song.released_year >= 2020 && strcmp(song.artist_name, "Tate McRae") == 0)
        {
            output(song);
        }
        break;
    case 3:
        if (strcmp(song.artist_name, "The Weeknd") == 0 && song.released_year < 2020 && strstr(song.mode, "Major") != NULL)
        {
            output(song);
        }
        break;
    case 4:
        if (song.released_year >= 2020 && song.in_spotify_playlists > 5000 && (strcmp(song.key, "D") == 0 || strcmp(song.key, "A") == 0))
        {
            output(song);
        }
        break;
    case 5:
        if (song.released_year >= 2021 && song.released_year <= 2022 && strstr(song.artist_name, "Drake") != NULL)
        {
            output(song);
        }
        break;
    default:
        break;
    }
}

Song parseLine(char *line)
{
    Song song;
    char *token = strtok(line, ",");
    if (token != NULL)
    {
        // copy all the fields using strcopy
        strncpy(song.track_name, token, sizeof(song.track_name) - 1);
        song.track_name[sizeof(song.track_name) - 1] = '\0'; // Ensure null-termination

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // Safely copy the artist_name
            strncpy(song.artist_name, token, sizeof(song.artist_name) - 1);
            song.artist_name[sizeof(song.artist_name) - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // copy the artist_count
            song.artist_count = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // copy the released_year
            song.released_year = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // copy the in_spotify_playlists
            song.in_spotify_playlists = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // copy the streams
            song.streams = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // copy the key
            strncpy(song.key, token, sizeof(song.key) - 1);
            song.key[sizeof(song.key) - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // copy the mode
            strncpy(song.mode, token, sizeof(song.mode) - 1);
            song.mode[sizeof(song.mode) - 1] = '\0';
        }
    }
    return song;
}

void output(Song song)
{
    char csvLine[MAX_LINE_LEN];
    FILE *outputFile = fopen("output.csv", "a"); // open the output file in append mode

    // format the song information as a CSV line
    sprintf(csvLine, "%s,%s\n", song.artist_name, song.track_name);

    // write the CSV line to output
    fputs(csvLine, outputFile);

    fclose(outputFile);
}