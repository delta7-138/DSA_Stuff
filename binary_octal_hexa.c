#include <stdio.h>
#include <string.h>
#define LARGE 10000
//Function to reverse a string 
char *reverse_str(char *str){
  int len = strlen(str); //length of the string 
 
  char temp[LARGE]; //storing the string temporarily for reversal
  strcpy(temp , str);
  for(int i = 0; i<len; i++){
    str[len -i - 1] = temp[i];
  }
  str[len] = '\0';
  return str;
}

//Function to add two numbers which are expressed as strings
void add_two_nums(char num1[] ,char num2[] , char sum[]){
  int len_num_1 = strlen(num1); //for length of first string
  int len_num_2 = strlen(num2); //for length of second string
  int len; 

  strcpy(num1 , reverse_str(num1)); //storing the reverse of the string 
  strcpy(num2 , reverse_str(num2)); //storing the reverse of the string

  //Since the lengths are unequal first equalizing them by adding zeroes at the end of the smaller string
  if(len_num_1>len_num_2){
    for(int i = len_num_2 ; i<len_num_1; i++){
      num2[i] = '0';
     }
     len = len_num_1;
     num2[len_num_1] = '\0';
  }
  else{
    for(int i = len_num_1; i<len_num_2; i++){
      num1[i] = '0';
    }
    len = len_num_2;
    num1[len_num_2]= '\0';
  }
  //Calculation of sum 
  int i = 0 ,carry = 0, ans_int = 0; //Variables for carry iterator and ans
  for(i = 0; i<len; i++){
    carry = carry + num1[i] - '0' + num2[i] - '0';
    sum[i] = (char)(carry%10 + '0');
    carry = carry/10;
  }
  //If final carry is 1
  if(carry!=0)
    sum[i] = (char)(carry%10 + '0');

  //Reversing the answer to get the real sum 
  strcpy(sum , reverse_str(sum));
  strcpy(num2 , reverse_str(num2)); //reversing the number back

  //printf("%s\n" , sum);
}

//Function to multiply to numbers one of which is represented as string
char * multiply(char num1[] , int num2 , char product[]){
  char temp[1000000] = "0";
  //Iteratively adding the number to get the product 
  for(int i = 0; i<num2; i++){
    add_two_nums(temp , num1 , temp);
    //printf("%s\n" , product);
  }
  strcpy(product , temp);
  return product;
}

//Function to convert four-digit binary string to hexadecimal character
char *convert_to_hex(char *string_inp , char *output){

  //Finding decimal equivalent of four digit binary string
  int ans = string_inp[strlen(string_inp)-1] - '0';
  for(int i = strlen(string_inp)-2; i>=0; i--){
    ans = ans * 2 + string_inp[i] - '0';
  }

  //Conversion to hexadecimal digit
  if(ans<10){
    output[0] = (char)(ans + '0');
  }else{
    output[0] = (char)(ans - 10 + 'A');
  }
  return output;

}

//Function to convert binary string into an octal digit
char *convert_to_oct(char *string_inp , char *output){

  //Conversion of three digit binary string into decimal equivalent
  int ans = string_inp[strlen(string_inp) - 1] - '0';
  for(int i = strlen(string_inp) - 2; i>=0; i--){
    ans = ans * 2 + string_inp[i] - '0';
  }
  //finding the octal digit
  output[0] = (char)(ans + '0');
  return output;
}

int main(){
    int n;
    scanf("%d" , &n);
    char bin_string[LARGE];
    scanf("%s" , bin_string);

    //Converting to decimal 
    char decimal_string[LARGE] ="0";
    decimal_string[0] = bin_string[0];
    for(int i = 1; i<n; i++){
        char temp[LARGE] = "0";
        temp[0] = bin_string[i]; 
        char temp_ans[LARGE];
        add_two_nums(multiply(decimal_string , 2 , temp_ans),temp ,decimal_string); //repeated multiplication with 2 and addition with the next digit 
    }

    //Converting to hexadecimal 
    char hexadecimal_string[LARGE] = "";
    int j = 0;
    for(int i = n-1; i>=0; i-=4 , j++){
        char temp_str[LARGE] = "";
        char output[LARGE] = "";
        int ctr = 0;
        //Loop to separate the binary strings into segments of length 4
        for(int k = i; k>i-4; k-- , ctr++){
            if(k<0){
                break;
            }
            temp_str[ctr] = bin_string[k];
        }
        temp_str[ctr] = '\0';
        convert_to_hex(temp_str , output); //Converting into respective hexadecimal digits
        strcat(hexadecimal_string , output); //Concatenating the digit with the result string
    }

    //Converting to octal
    char octal_string[LARGE] = "";
    j = 0; 
    for(int i = n-1; i>=0; i-=3 , j++){
      char temp_str[LARGE] = "";
      char output[LARGE] = "";
      int ctr = 0;
      //Loop to split the binary string into segments of length 3
      for(int k =i; k>i-3; k-- , ctr++){
        if(k<0) //In case the index becomes negative
          break;
        temp_str[ctr] = bin_string[k];
      }
      temp_str[ctr] ='\0';
      convert_to_oct(temp_str , output); //Converting into respective octal digits
      strcat(octal_string , output); //Concatentating the digit with the result string 
    }

    //Since the hexadecimal string and octal string is stored in reverse the result needs to be reversed before displaying
    printf("%s,%s,%s"  , decimal_string , reverse_str(hexadecimal_string) , reverse_str(octal_string)); 
    return 0;
}
