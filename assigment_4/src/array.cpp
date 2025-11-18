
int str_len(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    return i;

}

void tolower(char arr[]){
    int i=0;
    while (arr[i]!='\0')
    {
             if(arr[i]>='A' &&arr[i]<='Z'){
                arr[i]-='A';
                arr[i]+='a';
             }
             i++;
    }
    

}


void toUpper(char arr[]){
    int i=0;
    while (arr[i]!='\0')
    {
             if(arr[i]>='a' &&arr[i]<='z'){
                arr[i]-='a';
                arr[i]+='A';
             }

             i++;
    }
    

}


int str_concat(char str1[],char str2[],int size_str1){
int free_space=size_str1-str_len(str1);
int size_str2=str_len(str2);
int index_str1=size_str1-free_space ;
int index_str2=0;

if(free_space<size_str2) return -1;

for(;index_str1<size_str1;index_str1++,index_str2++){
    str1[index_str1]=str2[index_str2];
}
return 1;
}


int str_copy(char str1[],char str2[] ,int size_str1)
{
  int length_str2=str_len(str2);
  if(size_str1<length_str2)return 0;
int i=0;
  for(;i<length_str2;i++){
    str1[i]=str2[i];
  }
  if(i<size_str1){
    str1[i]='\0';
  }
return 1;
  
}


int str_cmp(char str1[],char str2[]){
    int length_str1=str_len(str1);
    int length_str2=str_len(str2);

    if(length_str1>length_str2)return 5;
    else if(length_str2>length_str1)return -5;

    for(int i=0;i<length_str1;i++){
            if(str1[i]>str2[i])return 1;
            else if(str1[i]<str2[i])return -1;
    }
    return 0;
}
