#include <stdio.h>
#include "framework.h"
#define charSize 50
//-----------------------------------------------------------------------------
// Computes and returns the length of a string 
//
// @param text string to check 
//
// @return length of the string
//
int stringLength(char *text);
int userChoice();
void formatSentance(char *text);
void cleenup(char *text);
void encription(char *text, char *text2);
void getKey(char *text, char *text2, int value);
void getRowCoulmn(int value, int *value1);
void getNewKey(char *text, char *text1, int *first, int *second);
void refreshSentance(char *text, char* text2, int value);
//-----------------------------------------------------------------------------
// Changes a string to upper case 
//
// @param text string to modify
//
void toUpper(char *text);
//-----------------------------------------------------------------------------
// Replace all the occurences of a letter in a string with another letter 
//
// @param text string to modify
// @param original letter to replace
// @param new_char letter used for the substitution
//
void replaceLetters(char *text, char original, char new_char);
//-----------------------------------------------------------------------------
int stringLength(char *text) 
{
  int i = 0;
  for (i = 0; i <= 25; i++)
  {
    if (*text == '\0')
    {
      break;
    }
    text++;
  }
  return i;
}

//-----------------------------------------------------------------------------
void toUpper(char *text) 
{
  for (int i = 0; i <= 25; i++)
  {
    if (*text != ' ' && *text >= 97 && *text <= 122)
    {
      *text = *text - 32;
    }
    if (*text == '\0')
    {
     break;
    }
    text++;
  }
}

//-----------------------------------------------------------------------------
void replaceLetters(char *text, char original, char new_char) 
{
  for (int i = 0; i <= 25; i++)
  {
    if (*text == original)
    {
      *text = new_char;
    }
    if (*text == '\0')
    {
     break;
    }
    text++;
  }
  // TODO: Implement
  // WARNING: Do not change the signature of the function
}
int userChoice()
{
  int userInputOption;
  int validInput = 0; 
  while (validInput == 0)
  {
    scanf("%i", &userInputOption);
    while ((getchar()) != '\n'); 
    if (userInputOption == 0 || userInputOption == 1 || userInputOption == 2)
    {
      validInput = 1;
    } 
  }
  return userInputOption;
}

void addLetter(char *text);
void addLetter(char *text)
{
  char temp[charSize];
  //int j = 0;
  for (int i = 0; i < charSize; i++)
  {
    temp[i] = '\0';
  }
  for (int i = 0, j = 0; i < charSize;  i++)//fliping, adding space
  {
    temp[i] = text[i - j];
    if (text[i] == text[i - 1])
    {
      j++;
    }
  }
  for (int i = 0; i < charSize; i++)
  {
    if (temp[i] == '\0')
    {
      break;
    }
    *text = temp[i];
    text++;
  }
  //*text = ;
}



void formatSentance(char *text)
{
  char temp[charSize];
  int j = 0;
  for (int i = 0; i < charSize; i++)
  {
    temp[i] = '\0';
  }
  //addLetter(&text[0]);
  for (int i = 0; i < charSize;  i++)//fliping, adding space
  {
    if ((i + 1)%3 == 0)
    {
      temp[i] = ' ';
      i++;
    }
    temp[i] = text[j];
    j++;
    if (text[j - 1 ] == '\0')
    {
      break;
    }
  }
  j = charSize;
  int i = 0;
  for (i = 0; i < charSize; i++)
  {
    if (temp[i] > 65 && temp[i] < 90 && temp[i+1] == '\0')
    {
      temp[i+1] = 'X';
      break;
    }
    if (temp[i] == '\0' || temp[i+1] == '\0')
    {
      break;
    }
    if (temp[i] == temp[i+1])
    {
      temp[i+1] = 'X';
    }
  }
  if (temp[i] == ' ')
    {
    temp[i] = '\0';
    }
  
  for (int i = 0; i < charSize; i++)
  {
    if (temp[i] == '\0')
    {
      break;
    }
    *text = temp[i];
    text++;
  }
}
void cleenup(char *text)  //calls the functions that set letters to uppercase and remove spaces
{
  toUpper(&text[0]);
  removeSpaces(&text[0]);
}
void encription(char *text, char *text2)  //cleans and formats the sentance so it is rady for eather encription or decription
{
  cleenup(&text[0]);
  formatSentance(&text[0]);
  text2++;
}
void getKey(char *text, char *text2, int value){ //it gets a binom of a sentance so it can be processed
  int test = value;
  test++;
  char temp[3] = {*text,*(text+1), ' ' };
  for (int i = 0; i < 3; i++)
  {
    *text2 = temp[i];
    text2++;
  }
  
}
void refreshSentance(char *text, char *text2, int value) //updates the sentance with the values that were eather encrepted or decrypted
{
  int j = value;
  for (int i = 0; i < j*3; i++)
  {
    text2++;
  }
  for (int i = 0; i < 3; i++)
  {
    *text2 = text[i];
    text2++;
  }
   

}
void getRowCoulmn(int value, int *value1){ // couldnt think of a more elegant solution(brute force it is)
  int Row;
  int Coulmn;
  switch (value)
  {
    case 0:
      Row = 0;
      Coulmn = 0;
      break;
    case 1:
      Row = 1;
      Coulmn = 0;
      break;
    case 2:
      Row = 2;
      Coulmn = 0;
      break;
    case 3:
      Row = 3;
      Coulmn = 0;
      break;
    case 4:
      Row = 4;
      Coulmn = 0;
      break;
    case 5:
      Row = 0;
      Coulmn = 1;
      break;
    case 6:
      Row = 1;
      Coulmn = 1;
      break;
    case 7:
      Row = 2;
      Coulmn = 1;
      break;
    case 8:
      Row = 3;
      Coulmn = 1;
      break;
    case 9:
      Row = 4;
      Coulmn = 1;
      break;
    case 10:
      Row = 0;
      Coulmn = 2;
      break;
    case 11:
      Row = 1;
      Coulmn = 2;
      break;
    case 12:
      Row = 2;
      Coulmn = 2;
      break;
    case 13:
      Row = 3;
      Coulmn = 2;
      break;
    case 14:
      Row = 4;
      Coulmn = 2;
      break;
    case 15:
      Row = 0;
      Coulmn = 3;
      break;
    case 16:
      Row = 1;
      Coulmn = 3;
      break;
    case 17:
      Row = 2;
      Coulmn = 3;
      break;
    case 18:
      Row = 3;
      Coulmn = 3;
      break;
    case 19:
      Row = 4;
      Coulmn = 3;
      break;
    case 20:
      Row = 0;
      Coulmn = 4;
      break;
    case 21:
      Row = 1;
      Coulmn = 4;
      break;
    case 22:
      Row = 2;
      Coulmn = 4;
      break;
    case 23:
      Row = 3;
      Coulmn = 4;
      break;
    case 24:
      Row = 4;
      Coulmn = 4;
      break;
  }
  // attention, the row and column is reversed!!!
  *value1 = Coulmn;
  value1++;
  *value1 = Row;
  value1++;
  *value1 = value;
}
void getNewKey(char *text,char *text1, int *first, int *second) //it assigns the key to the new position
{
  int temp = 5 * first[0];
  first++;
  temp = temp + first[0];
  *text = text1[temp];
  text++;


  temp = 0;
  temp = 5 * second[0];
  second++;
  temp = temp + second[0];
  *text = text1[temp];
}


int main()
{
  char userInput[25] = {0};
  char providedSentance[50];
  char keyinProcessing[3] = {'\0','\0', '\0' };
  int choice;
  for (int k = 0; k < 25; k++) //makes sure that the array is empty
  { 
    userInput[k] = '\0';
  }
  for (int k = 0; k < 50; k++) //makes sure that the array is empty
  { 
    providedSentance[k] = '\0';
  }
  generatePlayfairSquare(&userInput[0]);
  int infinity = 1;
  do
  {
    printf("\n");
    printf("Wählen Sie bitte eine Option:\n1 - Verschlüsseln\n2 - Entschlüsseln\n0 - Programm beenden\n");
    printf("\n");
    choice = userChoice();
    if (choice == 0)
    {
      return(0);
    }
    if (choice == 1)
    {
      printf("Klartext: "); //encription
      scanf("%[^\n]s", providedSentance);
      while ((getchar()) != '\n');
      addLetter(&providedSentance[0]);
      encription(&providedSentance[0],&userInput[0]);
      printf("Vorbereiteter Klartext: %s\n", providedSentance);
      int i = 0;
      do
      {
        int nr1 = 0;// set it so that this number contains row colmun, value of the number
        int nr2 = 0;
        int location1[3] = {'\0','\0','\0'};
        int location2[3] ={'\0','\0','\0'};
        getKey(&providedSentance[i*3], &keyinProcessing[0], i);
        while (keyinProcessing[0] != userInput[nr1])
        {
          nr1++;
        }
        
        getRowCoulmn(nr1, &location1[0]);

        while (keyinProcessing[1] != userInput[nr2])
        {
          nr2++;
        }
        getRowCoulmn(nr2, &location2[0]);
        if (location1[0] == location2[0])
        {
          location1[1]++;
          if (location1[1] == 5)
          {
            location1[1] = 0;
          }
          location2[1]++;
          if (location2[1] == 5)
          {
            location2[1] = 0;
          }
          //move first and second letter to the right
        }
        else if (location1[1] == location2[1])
        {
          location1[0]++;
          if (location1[0] == 5)
          {
            location1[0] = 0;
          }
          location2[0]++;
          if (location2[0] == 5)
          {
            location2[0] = 0;
          }
          //move first and second letter bellow
        }
        else
        {
          int temp = location1[1];
          location1[1] = location2[1];
          location2[1] = temp;
        }
        getNewKey(&keyinProcessing[0],&userInput[0], &location1[0], &location2[0]);
        refreshSentance(&keyinProcessing[0],&providedSentance[0], i);
        
        
        i++;
      } while (providedSentance[i*3] != '\0');
      printf("Ciphertext: ");
      for (int i = 49; 0 < i; i--)  //making sure that the testcases can read the format correctly
        {
          if (providedSentance[i] == ' ')
          {
            providedSentance[i] = '\0';
            break;
          }
          
        }
      for (int i = 0; i < 50; i++)  //
      {
        
        if (providedSentance[i] == '\0')
        {
          break;
        }
        printf("%c", providedSentance[i]);
      }
      printf("\n");
      
    }
    if (choice == 2)
    {
      printf("Ciphertext: "); //decription
      scanf("%[^\n]s", providedSentance);
      while ((getchar()) != '\n');
      encription(&providedSentance[0],&userInput[0]);
      printf("Vorbereiteter Ciphertext: %s\n", providedSentance);
      int i = 0;
      do
      {
        int nr1 = 0;// set it so that this number contains row colmun, value of the number
        int nr2 = 0;
        int location1[3] = {'\0','\0','\0'};
        int location2[3] ={'\0','\0','\0'};
        getKey(&providedSentance[i*3], &keyinProcessing[0], i);
        while (keyinProcessing[0] != userInput[nr1])
        {
          nr1++;
        }
        getRowCoulmn(nr1, &location1[0]);
        while (keyinProcessing[1] != userInput[nr2])
        {
          nr2++;
        }
        getRowCoulmn(nr2, &location2[0]);
        if (location1[0] == location2[0])
        {
          location1[1]--;
          if (location1[1] == -1)
          {
            location1[1] = 4;
          }
          location2[1]--;
          if (location2[1] == -1)
          {
            location2[1] = 4;
          }
          //move first and second letter to the right
        }
        else if (location1[1] == location2[1])
        {
          location1[0]--;
          if (location1[0] == -1)
          {
            location1[0] = 4;
          }
          location2[0]--;
          if (location2[0] == -1)
          {
            location2[0] = 4;
          }
          //move first and second letter bellow
        }
        else
        {
          int temp = location1[1];
          location1[1] = location2[1];
          location2[1] = temp;
          //jednu os zameni sad osi drugog
        }
        getNewKey(&keyinProcessing[0],&userInput[0], &location1[0], &location2[0]);
        refreshSentance(&keyinProcessing[0],&providedSentance[0], i);
        
        
        i++;
        //replaceLetters to za izmjenu kljuca
      } while (providedSentance[i*3] != '\0');
      printf("Klartext: ");
      for (int i = 49; 0 < i; i--)  //making sure that the testcases can read the format correctly
        {
          if (providedSentance[i] == ' ')
          {
            providedSentance[i] = '\0';
            break;
          }
          
        }
      for (int i = 0; i < 50; i++)  //
      {
        
        if (providedSentance[i] == '\0')
        {
          break;
        }
        printf("%c", providedSentance[i]);
      }
      printf("\n");
      
    }
  } while (infinity == 1);
  
}
