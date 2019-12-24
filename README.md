# 주소록 프로그램 만들기
** 제출기한: ** 2019년 12월 22일
** 제출방법: ** 별도로 제출할 필요 없습니다. repl.it 강의실에 projects 메뉴를 통해 작성해두면 23일에 일괄적으로 채점할 예정입니다.
** 주의: ** 만일 projects 메뉴가 아닌 별도의 방법으로 작성한다면 채점이 불가능하며 0점처리 됩니다.


### ◎ 주소록에 저장할 자료
연락처에는 이름, 전화번호, 생일이 저장된다.
* 이름은 '\0'을 제외하고 최대 20bytes
* 전화번호는 '-'를 제외하고 최대 15bytes
* 생일은 YYYYMMDD 형식으로 8bytes

이름, 전화번호, 생일에 입력되는 정보는 검증하지 않는다.
이름은 영어 대소문자로 입력되며 중복되지 않지만, 나머지 정보는 중복될 수 있다.
최대 100명의 정보를 저장할 수 있어야 한다.
정보는 구조체를 이용하여 표현하고, 배열을 사용하여 여러 사람의 정보를 저장한다. 즉, 구조체 배열을 사용한다.
필요한 경우 구조체에 다른 부가 정보를 저장해도 무관하다.

### ◎ 기능
프로그램은 아래의 기능을 포함해야 한다.
* 사람의 정보를 입력받아 등록하는 기능
* 이름으로 검색하여 정보를 삭제하는 기능
* 원하는 달을 입력받아 그 달이 생일인 사람의 정보를 출력하는 기능
* 등록된 전체 사람들의 정보를 출력하는 기능

등록기능은 사용자로부터 이름, 전화번호, 생일을 입력받아 프로그램에 저장하는 기능이다.
사람의 정보를 출력할 때는 이름, 전화번호, 생일을 함께 출력해야 한다.

### ◎ 유저 인터페이스
콘솔 모드에서 메뉴방식으로 동작하고, 표준 입출력을 사용한다.
프로그램이 처음 실행되면 사용자가 선택할 수 있는 메뉴들을 화면에 출력한 후, 입력을 기다린다.
메뉴는 `1. Registration, 2. Show all, 3. Delete, 4. FindByBirth, 5. Exit` 등 모두 다섯가지이다.
선택된 메뉴에 따라 적절한 동작을 수행하다가 `5. Exit`이 선택되면 종료한다.

메뉴 선택 시 다음 제시된 코드를 사용하여 안내 화면을 출력한다.
```
printf("*****Menu*****\n");
printf("1. Registration, 2. ShowAll, 3. Delete, 4. FindByBirth, 5. Exit\n");
printf("Enter the menu number:");
```
사용자는 1 ~ 5 사이의 숫자를 하나 입력하며, 잘못된 입력은 없다고 가정한다.

  ##### ○ Registration
  1이 입력되면 (`1. Registration` 메뉴 선택) 아래의 코드를 사용하여 정보를 입력받는다.
  이름, 전화번호, 생일을 차례로 입력받는다.
  ```
  printf("Name:");  // 고정
  ...
  printf("Phone number:"); // 고정
  ...
  printf("Birth:"); //고정
  ...
  ```  
  등록이 완료되면 `printf(“count: %d\n”, ..);` 문장을 이용하여 현재 저장되어 있는 연락처의 개수를 출력한 수 메뉴로 복귀한다.
  만일 최대 저장 가능한 개수를 초과한 경우에는 `printf("Overflow.\n");`를 실행한 후 메뉴로 복귀한다.

  ##### ○ ShowAll
  2가 입력되면 (`2. ShowAll` 메뉴 선택) 틍록된 모든 사람의 정보를 저장된 순서대로 출력한다.
  한 줄에 한 명씩 등록된 사람의 정보를 아래 코드를 이용하여 출력한다.
  ```
  printf("%s %s %s\n", ... );
  ```
  단, 등록된 정보가 없으면 아무것도 출력하지 않고 메뉴로 복귀한다.

  ##### ○ Delete
  3이 입력되면 (`3. Delete` 메뉴 선택) 아래 코드와 같이 이름을 입력받는다.
  ```
  printf("Name:");  // 고정
  ...
  ```
  이름에 해당하는 연락처를 삭제한다.
  만일 해당 연락처가 없다면 `printf("No record founded.\n");`를 실행한 후, 메뉴로 복귀한다.

  ##### ○ FindByBirth
  4가 입력되면 (`4. FindByBirth` 메뉴 선택) 아래 코드와 같이 생일 달을 입력받는다.
  ```
  printf("Birth:");  // 고정
  ...
  ```
  사용자는 1 ~ 12사이의 숫자를 하나 입력하며, 잘못된 입력은 없다고 가정한다.
  입력받은 달에 생일인 사람의 정보(이름, 전화번호, 생일)를 아래 코드를 이용하여 출력한다.
  ```
  printf("%s %s %s\n", ... );
  ```
  같은 달에 생일인 사람이 여러 명인 경우, 자료가 저장되어 있는 순서대로 출력한다.
  생일인 사용자가 없다면 무시하고 메뉴로 복귀한다.

  ##### ○ Exit
  5가 입력되면 (`5. Exit` 메뉴 선택) 프로그램을 종료한다.

### ◎ 구현 조건
다음의 함수들을 구현해서 사용해야 한다. (제시된 것보다 더 세분화하여 구현해도 무방한다.)
- 자료 등록을 처리하는 함수
- 전체 보기를 처리하는 함수
- 자료 삭제를 처리하는 함수
- 주어진 달에 생일인 회원을 검색하는 함수

### ◎ 입력 형식
표준입력(`stdin`)으로 입력된다.
메뉴 선택 부분에서는 1 ~ 5 사이의 숫자가 입력된다.
이름, 전화번호, 생일을 입력하는 부분에서는 각각 하나의 문자열이 입력된다.
잘못된 입력은 없다고 가정한다.
같은 이름은 입력되지 않는다.

### ◎ 출력 형식
표준출력(`stdout`)으로 출력한다.
안내 화면 및 등록된 사람의 정보를 출력할 때는, 위에서 제시한 코드를 그대로 사용한다.

### ★ 추가점수 1
입력되는 데이터를 ABC 순서로 정렬하여 관리할 경우 추가점수를 얻을 수 있다.
ABC 순서라 함은 아스키 코드상의 순서를 말하며 `strcmp` 함수를 이용하여 순서를 판단할 수 있다.
이 경우 출력 시 화면에 표시되는 사람 정보의 순서가 달라질 수 있다.

### ★ 추가점수 2
분할 컴파일이 가능하도록 소스코드와 헤더파일을 분리할 경우 추가점수를 얻을 수 있다.
소스코드는 적어도 3개로 구성되어야 한다.
예를 들어, 구조체 선언, 변수 선언, 함수 선언 등으로 헤더 파일을 나눌 수 있다.
헤더파일은 `#ifndef` 를 이용하여 필요한 경우에만 포함되도록 조절한다.
이외 헤더파일이나 소스코드의 종류는 작성자가 수정할 수 있다.

### ★ 추가점수 3
연락처를 저장할 구조체에 배열이 아닌 포인터를 사용할 경우 추가점수를 얻을 수 있다.
아래의 코드는 배열을 이용한 구조체의 예시이다.
```
struct 구조체이름 {
  char 이름변수[21];
  char 전화번호변수[16];
  char 생일변수[9];
};
struct 구조체이름 구조체변수이름[100];
```
추가점수를 얻기 위해서는 위의 코드 대신 아래의 코드를 사용해야 한다.
```
struct 구조체이름 {
  char *이름변수;
  char *전화번호변수;
  char *생일변수;
};
struct 구조체이름 **구조체변수이름;
```
필요한 경우 구조체에 필드를 추가할 수 있다.

### ★ 추가점수 4
저장할 데이터를 무한히 받을 수 있도록 확장할 경우 추가점수를 얻을 수 있다.
이 경우 100개 이상의 데이터를 받더라도 Overflow가 발생하지 않으며, 메모리가 허용하는 한 무한히 많은 데이터를 저장할 수 있다.
힌트: linked list 이용

### ★ 추가점수 5
파일을 이용하여 사용자의 정보를 유지할 수 있도록 확장할 경우 추가점수를 얻을 수 있다.
이를 위해서는 프로그램 시작 시 파일로부터 사용자의 정보를 읽고 데이터를 채워야 한다.
새로운 데이터를 입력 받을 경우 해당하는 사람 정보를 파일에 기록해야 한다.
삭제할 경우 파일에서 해당하는 사람의 정보를 파일에서 지워야 한다.

### **주의**
  공백 하나라도 차이가 나면 채점 시스템에서 오답으로 처리가 될 수 있으므로, 제시된 것 이외의 추가적인 출력문을 사용하지 말 것
  프로그램 소스에는 적절한 들여쓰이과 주석을 달 것
  표준 함수(예: `string.h`)만을 사용하여 프로그램을 작성할 것. algorithm 헤더와 STL 사용 불가

입출력 테스트 예시는 EXAMPLE 파일을 참고할 것