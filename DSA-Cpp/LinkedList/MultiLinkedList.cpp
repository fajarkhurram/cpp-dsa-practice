# include <iostream>
using namespace std;

class S_Node{
public:
    int SeatNo;
    S_Node* s_next;
};

class C_Node{
public :
    int courseNO;
    C_Node* c_next;
    S_Node* stu_list; //HEAD OF STUDENT LIST 
};

class MultiList{
    C_Node* c_list; //head
public:
    MultiList(){
        c_list = NULL;
    }

    void insert_course(int courseNo){
        C_Node* newNode = new C_Node();
        newNode->courseNO = courseNo;
        newNode->c_next = NULL;
        newNode->stu_list = NULL;

        if(c_list == NULL){
            c_list = newNode;
            return;
        }
        else{
            C_Node* c_curr = c_list;
            while(c_curr->c_next != NULL){
                c_curr = c_curr->c_next;
            }
            c_curr->c_next = newNode;
            return;
        }
    }

    void insert_student(int seatNo , int courseNO){
        C_Node* c_curr = c_list;
        

         while(c_curr != NULL){
            if(courseNO == c_curr->courseNO){
                S_Node* newNode = new S_Node();
                newNode->SeatNo = seatNo;
                newNode->s_next = NULL;
            
                if(c_curr->stu_list == NULL){
                c_curr->stu_list = newNode;
                }
                    else{
                S_Node* s_curr = c_curr->stu_list;
                while(s_curr->s_next != NULL){
                    s_curr = s_curr->s_next;
                }
                s_curr->s_next = newNode;
                
            }
            return;
            
         }
         c_curr = c_curr->c_next;
    }
    cout << "Course not found!" << endl;
}
    // DELETE A COURSE (with all its students)
    void delete_course(int courseNo) {
        C_Node* c_curr = c_list;
        C_Node* c_prev = NULL;

        while (c_curr != NULL) {
            if (c_curr->courseNO == courseNo) {
                //  delete all students linked to this course
                S_Node* s_curr = c_curr->stu_list;
                while (s_curr != NULL) {
                    S_Node* temp = s_curr;
                    s_curr = s_curr->s_next;
                    delete temp;
                }

                // remove course node from linked list
                if (c_prev == NULL) {
                    c_list = c_curr->c_next; // course is head
                } else {
                    c_prev->c_next = c_curr->c_next;
                }
                delete c_curr;
                cout << "Course " << courseNo << " deleted successfully." << endl;
                return;
            }
            c_prev = c_curr;
            c_curr = c_curr->c_next;
        }

        cout << "Course not found!" << endl;
    }

    //  SEARCH A COURSE
    bool search_course(int courseNo) {
        C_Node* c_curr = c_list;
        while (c_curr != NULL) {
            if (c_curr->courseNO == courseNo) {
                cout << "Course " << courseNo << " found." << endl;
                return true;
            }
            c_curr = c_curr->c_next;
        }
        cout << "Course " << courseNo << " not found." << endl;
        return false;
    }

    //DELETE A STUDENT FROM A SPECIFIC COURSE
    void delete_student_from_course(int seatNo, int courseNo) {
        C_Node* c_curr = c_list;

        while (c_curr != NULL) {
            if (c_curr->courseNO == courseNo) {
                S_Node* s_curr = c_curr->stu_list;
                S_Node* s_prev = NULL;

                while (s_curr != NULL) {
                    if (s_curr->SeatNo == seatNo) {
                        if (s_prev == NULL)
                            c_curr->stu_list = s_curr->s_next; // student is first
                        else
                            s_prev->s_next = s_curr->s_next;

                        delete s_curr;
                        cout << "Student " << seatNo << " deleted from course " << courseNo << endl;
                        return;
                    }
                    s_prev = s_curr;
                    s_curr = s_curr->s_next;
                }

                cout << "Student not found in course " << courseNo << endl;
                return;
            }
            c_curr = c_curr->c_next;
        }

        cout << "Course not found!" << endl;
    }


    //DELETE A STUDENT FROM EVERY COURSE HE IS ENROLLED IN
    void delete_student_everywhere(int seatNo) {
        C_Node* c_curr = c_list;

        bool found = false;
        while (c_curr != NULL) {
            S_Node* s_curr = c_curr->stu_list;
            S_Node* s_prev = NULL;

            while (s_curr != NULL) {
                if (s_curr->SeatNo == seatNo) {
                    if (s_prev == NULL)
                        c_curr->stu_list = s_curr->s_next;
                    else
                        s_prev->s_next = s_curr->s_next;

                    S_Node* temp = s_curr;
                    s_curr = s_curr->s_next;
                    delete temp;
                    found = true;
                    continue; // continue without moving s_prev
                }
                s_prev = s_curr;
                s_curr = s_curr->s_next;
            }
            c_curr = c_curr->c_next;
        }

        if (found)
            cout << "Student " << seatNo << " deleted from all courses." << endl;
        else
            cout << "Student " << seatNo << " not found in any course." << endl;
    }


    //  SEARCH STUDENT IN A SPECIFIC COURSE
    bool search_student_in_course(int seatNo, int courseNo) {
        C_Node* c_curr = c_list;

        while (c_curr != NULL) {
            if (c_curr->courseNO == courseNo) {
                S_Node* s_curr = c_curr->stu_list;
                while (s_curr != NULL) {
                    if (s_curr->SeatNo == seatNo) {
                        cout << "Student " << seatNo << " found in course " << courseNo << endl;
                        return true;
                    }
                    s_curr = s_curr->s_next;
                }
                cout << "Student not found in course " << courseNo << endl;
                return false;
            }
            c_curr = c_curr->c_next;
        }

        cout << "Course not found!" << endl;
        return false;
    }

    //SEARCH STUDENT IN ALL COURSES
    void search_student_everywhere(int seatNo) {
        C_Node* c_curr = c_list;
        bool found = false;

        while (c_curr != NULL) {
            S_Node* s_curr = c_curr->stu_list;
            while (s_curr != NULL) {
                if (s_curr->SeatNo == seatNo) {
                    cout << "Student " << seatNo << " is in course " << c_curr->courseNO << endl;
                    found = true;
                }
                s_curr = s_curr->s_next;
            }
            c_curr = c_curr->c_next;
        }

        if (!found)
            cout << "Student " << seatNo << " not found in any course." << endl;
    }

    //  DISPLAY STUDENT LIST OF A SPECIFIC COURSE
    void display_students_of_course(int courseNo) {
        C_Node* c_curr = c_list;

        while (c_curr != NULL) {
            if (c_curr->courseNO == courseNo) {
                cout << "Course " << courseNo << " | ";

                S_Node* s_curr = c_curr->stu_list;
                if (s_curr == NULL)
                    cout << "No students";
                else {
                    while (s_curr != NULL) {
                        cout << s_curr->SeatNo << " -> ";
                        s_curr = s_curr->s_next;
                    }
                    cout << "NULL";
                }
                cout << endl;
                return;
            }
            c_curr = c_curr->c_next;
        }

        cout << "Course not found!" << endl;
    }


    void DisplayAll(){
        C_Node* c_curr = c_list;

        if(c_curr == NULL){
            cout << "No course offered";
        }
       
        while(c_curr!=NULL){
            cout << "Course "<<c_curr->courseNO << endl << "|";

            S_Node* s_curr = c_curr->stu_list;
            if(s_curr == NULL){
                cout << "No student enrolled in this course";
            }
            else{
                while(s_curr != NULL)
            {
                cout << s_curr->SeatNo << "->" ;
                s_curr= s_curr->s_next;
            }
            cout << "NULL" ;
            
        }
        cout << endl;
        c_curr = c_curr->c_next ;
    }
    }
};

int main() {
    MultiList ml;

    bool flag = true;
    while (flag) {
        int choice;
        cout << "\nEnter the function number you want to perform:" << endl;
        cout << "1) INSERT COURSE\n"
             << "2) ENROLL A STUDENT IN A COURSE\n"
             << "3) DISPLAY ALL COURSES & STUDENTS\n"
             << "4) DELETE A COURSE\n"
             << "5) SEARCH A COURSE\n"
             << "6) DELETE A STUDENT FROM A COURSE\n"
             << "7) DELETE A STUDENT FROM ALL COURSES\n"
             << "8) SEARCH A STUDENT IN A COURSE\n"
             << "9) SEARCH A STUDENT IN ALL COURSES\n"
             << "10) DISPLAY STUDENTS OF A COURSE\n"
             << "11) EXIT\n";
        cin >> choice;

        int courseNo, seatNo;

        switch (choice) {
            case 1:
                cout << "ENTER COURSE YOU WANT TO OFFER: ";
                cin >> courseNo;
                ml.insert_course(courseNo);
                break;

            case 2:
                cout << "ENTER STUDENT'S SEAT NO: ";
                cin >> seatNo;
                cout << "ENTER COURSE NO: ";
                cin >> courseNo;
                ml.insert_student(seatNo, courseNo);
                break;

            case 3:
                ml.DisplayAll();
                break;

            case 4:
                cout << "ENTER COURSE NO TO DELETE: ";
                cin >> courseNo;
                ml.delete_course(courseNo);
                break;

            case 5:
                cout << "ENTER COURSE NO TO SEARCH: ";
                cin >> courseNo;
                ml.search_course(courseNo);
                break;

            case 6:
                cout << "ENTER STUDENT'S SEAT NO TO DELETE: ";
                cin >> seatNo;
                cout << "ENTER COURSE NO: ";
                cin >> courseNo;
                ml.delete_student_from_course(seatNo, courseNo);
                break;

            case 7:
                cout << "ENTER STUDENT'S SEAT NO TO DELETE FROM ALL COURSES: ";
                cin >> seatNo;
                ml.delete_student_everywhere(seatNo);
                break;

            case 8:
                cout << "ENTER STUDENT'S SEAT NO TO SEARCH: ";
                cin >> seatNo;
                cout << "ENTER COURSE NO: ";
                cin >> courseNo;
                ml.search_student_in_course(seatNo, courseNo);
                break;

            case 9:
                cout << "ENTER STUDENT'S SEAT NO TO SEARCH IN ALL COURSES: ";
                cin >> seatNo;
                ml.search_student_everywhere(seatNo);
                break;

            case 10:
                cout << "ENTER COURSE NO TO DISPLAY STUDENTS: ";
                cin >> courseNo;
                ml.display_students_of_course(courseNo);
                break;

            case 11:
                cout << "Program ended" << endl;
                cout << "=================" << endl;
                flag = false;
                break;

            default:
                cout << "INVALID CHOICE! TRY AGAIN." << endl;
        }
    }

    return 0;
}
