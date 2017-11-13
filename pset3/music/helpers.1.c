// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = atoi(strtok(fraction, "/"));
    int denominator = atoi(strtok(NULL, "/"));

    int eigths = 0;

    ////eprintf ("%i %i\n", numerator, denominator);

    switch(denominator)
    {
        case 2:
            eigths =  4*numerator;
            //eprintf("achtel %i\n", eigths);
            return eigths;
        break;

        case 4:
             eigths =  2*numerator;
             //eprintf("achtel %i\n", eigths);
             return eigths;
        break;

        case 8:
            eigths =  numerator;
            //eprintf("achtel %i\n", eigths);
            return eigths;
        break;

    }
    //eprintf("achtel %i\n", eigths);
    return eigths;
}

// Calculates frequency (in Hz) of a note, takes a string for a note e.g A4
int frequency(string note)
{
    // TODO
    //The frequency, f, of some note is 2^n/12 × 440, where n is the number of semitones from that note to A4.
    //where n is negative when lower then A4 and positive when greater then A4

    char key = note[0];


    int halftones = 0;

    //how many halftones is the current note away from A ?
    switch(key)
    {
        case 'C':
            halftones = -9;
        break;

        case 'D':
            halftones = -7;
        break;

        case 'E':
            halftones = -5;
        break;

        case 'F':
            halftones = -4;
        break;

        case 'G':
            halftones = -2;
        break;

        case 'A':
            halftones = 0;
        break;

        case 'B':
            halftones = +2;
        break;

       //defaul
    }

    char oct[1] = " ";
    char accidental[1] = " ";
    int octave = 0;

    //do we have a note which includes an accidental ? also check the octave now
    //no
    if (strlen(note) == 2)
    {
        oct[0] = note[1];
        octave = atoi(oct);
    }

    //yes
    if (strlen(note) == 3)
    {
        accidental[0] = note[1];
        oct[0] = note[2];
        octave = atoi(oct);
    }

    //eprintf("octavevalue %i\n", octave);

    int additional_halftones = 0;

    //add (or subtract) additional halftones from octave difference..
    if (octave == 4)
    {
        additional_halftones = 0;
    }

    if (octave < 4)
    {
        additional_halftones = -12 * (4 - octave);
    }

    if (octave > 4)
    {
        additional_halftones = 12 * (octave - 4);
    }

    //add correction for the accidental
    if (memcmp(accidental, "#", 1) == 0)
    {
        additional_halftones++;
    }

    if (memcmp(accidental, "b", 1) == 0)
    {
        additional_halftones--;
    }


    //add the halftones from the key shift and the octave shif together to get the correct amount of halftones the note "n" is away from A4
    int halftonesaway = halftones + additional_halftones;

     // TODO
    //The frequency, f, of some note is 2^n/12 × 440, where n is the number of semitones from that note to A4.
    //where n is negative when lower then A4 and positive when greater then A4

    double y = halftonesaway/12.0f;

    double frequency =  pow(2, y) * 440;

    //eprintf("frequency: %f\n", frequency);

    //does this work with the typecast ?
    return (int) round (frequency);


    //check the string for note, accidental, octave

    //calculate number of halftones away from A that current note is



    //put final halftones into formula and calc frequency

    //round frequency to nearest integer then return


}

// Determines whether a string represents a rest, a blank line should be "" according to CS50 library documentation
bool is_rest(string s)
{
    int result = memcmp(s, "",1);
    return (result == 0) ? true : false;
}
