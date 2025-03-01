#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 100
int top=-1;
int stack[MAX];
int h;//randomizes if vowels or consonants are to be replaced
char return_a_num(int num){
    return num+'0';
}
void checkh(){
    h=rand()%2;
}
void push(int data)
{
    if(top==MAX-1)
    {
        printf("Full");

    }
    else
    {
        top++;
        stack[top]=data;
    }
}
void pop(){
    if(top==-1){
        printf("Empty");
    }
    else{
        top--;
    }
}
void display(){
    if(top==-1){
        printf("Empty");
    }
    else{
        for(int i=0;i<top+1;i++){
            printf("%c",(char)stack[i]);
        }
    }
}
//checks for hierarchy and replaces with new password
char hierarchy(char a){
    if(h==0){
    if(a=='a'||a=='A'){
        return '^';
    }
    else if(a=='e'||a=='E'){
        return '@';
    }
    else if(a=='i'||a=='I'){
        char b=return_a_num(1);
        return b;
    }
    else if(a=='o'||a=='O'){
        char b=return_a_num(0);
        return b;
    }
    else if(a=='u'||a=='U'){
        return ')';
    }
    else{
        return a;
    }
}
    else{
    if(a=='h'||a=='H'){
        return '#';
    }
    else if(a=='e'||a=='E'){
        char b;
        b=return_a_num(3);
        return b;
    }
    else if(a=='s' || a=='S'){
        return '$';
    }
    else if(a=='d' || a=='D'){
        return ']';
    }
    else if(a=='r' || a=='R'){
        return '%';
    }
    else if(a=='l' || a=='L'){
        return '<';
    }
    else if(a=='t' || a=='T'){
        return '+';
    }
    else if(a=='m'||a=='M'){
        return 'w';
    }
    else if(a=='w'||a=='W'){
        return 'm';
    }
    else if(a=='c'||a=='C'){
        return '(';
    }
    else if(a=='p'||a=='P'){
        char b;
        b=return_a_num(9);
        return b;
    }
    else if(a=='b'||a=='B'){
        char b;
        b=return_a_num(8);
        return b;
    }
    else if(a=='v'||a=='V'){
        return '>';
    }
    else{
        return a;
    }
}
}
void seperator(){
    int x;
    x=rand()%5;
    char g;
    switch(x){
        case 0:
             g='.';
            break;
        case 1:
             g='/';
            break;     
        case 2:
             g='?';
            break;
        case 3: 
             g='|';
            break;
        case 4: 
             g=':';
            break;
        default:
             g='-';
            break;
    }
    push(g);
}


int main()
{
    printf("\nWelcome to the password generator");
    printf("\n**********************************");
    printf("\nThis program will generate a password for you and save it in a file");
    srand(time(0));
    char exp[100],*e,x;
    printf("\nEnter the password:");
    scanf("%s",exp);
    e=exp;
    int r=0;
    int begorend=rand()%2;
    if(begorend==0){
        seperator();
    }
    checkh();
    while(*e!='\0'){
        //change 1st letter to uppercase
        if(*e != 'a' && *e != 'e' && *e != 'i' && *e != 'o' && *e != 'u' &&
            *e != 'h' && *e != 'e' && *e != 's' && *e != 'd' && *e != 'r' &&
            *e != 'l' && *e != 't' && *e != 'A' && *e != 'E' && *e != 'I' &&
            *e != 'O' && *e != 'U' && *e != 'H' && *e != 'E' && *e != 'S' &&
            *e != 'D' && *e != 'R' && *e != 'L' && *e != 'T'&& *e!='m'&& *e!='w'
            && *e!='c'&& *e!='p'&& *e!='b'&& *e!='v'&&*e!='M'&& *e!='W' && *e!='C'&& *e!='P'&& *e!='B'&& *e!='V'
            &&r==0 && islower(*e))
        {
            char f=*e-32;
            push(f);
            r=1;
        }
        //push number
        else if(isdigit(*e)){
            push(*e);
        }
        //change and push special characters
        else if (*e == 'a' || *e == 'e' || *e == 'i' || *e == 'o' || *e == 'u' ||
            *e == 'h' || *e == 'e' || *e == 's' || *e == 'd' || *e == 'r' ||
            *e == 'l' || *e == 't' || *e == 'A' || *e == 'E' || *e == 'I' ||
            *e == 'O' || *e == 'U' || *e == 'H' || *e == 'E' || *e == 'S' ||
            *e == 'D' || *e == 'R' || *e == 'L' || *e == 'T')
        {
            char d=hierarchy(*e);
            push(d);
        }  
        else{
        push(*e);
        }
        e++;      
    
    }
    if(begorend==1){
        seperator();
    }
    printf("\nNew password generated:");
    display();
    for(int i=0;i<top+1;i++){
        x=(char)stack[i];
        //printf("%c",x);
    }

    // Convert stack to a string
    char stack_str[MAX + 1];
    for(int i=0; i<=top; i++){
        stack_str[i] = (char)stack[i];
    }
    stack_str[top + 1] = '\0'; // Null-terminate the string
    char finalpassword[1000];
    strcpy(finalpassword,exp);
    strcat(finalpassword,"=");
    strcat(finalpassword,stack_str);
    char command[1000];
    char name[1000];
    printf("\nEnter the name of the file for the filepath:");
    scanf("%s",name);
    snprintf(command, sizeof(command), 
    "powershell -Command \"if (!(Test-Path 'C:\\\\Users\\\\%s\\\\cool_password.txt')) { "
    "New-Item -Path 'C:\\\\Users\\\\%s\\\\cool_password.txt' -ItemType File }; "
    "Add-Content -Path 'C:\\\\Users\\\\%s\\\\cool_password.txt' -Value '%s'\"", 
    name,name,name,finalpassword);
    int ret=system(command);
    if(ret==0){
        printf("\nPassword saved successfully in C:\\Users\\%s\\cool_password.txt",name);
        printf("\nPassword: %s",finalpassword);

    }
    else{
        printf("\nPassword not saved in C:\\Users\\%s\\cool_password.txt",name);
    }
    return 0;
}
