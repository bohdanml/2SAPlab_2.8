#include <iostream>
#include <string>

using namespace std;

struct Applicant {
    string surname;
    float certificateScore;
    string educationDocument;
    Applicant* next;
    Applicant* prev;

    Applicant() : certificateScore(0), next(nullptr), prev(nullptr) {}
};
void addApplicant(Applicant*& head, string surname, float certificateScore, string educationDocument) {
    Applicant* newNode = new Applicant;
    newNode->surname = surname;
    newNode->certificateScore = certificateScore;
    newNode->educationDocument = educationDocument;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    }
    else {
        Applicant* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(Applicant* head) {
    Applicant* temp = head;
    while (temp != nullptr) {
        cout << "Surname: " << temp->surname << ", Certificate Score: " << temp->certificateScore << ", Education Document: " << temp->educationDocument << endl;
        temp = temp->next;
    }
}

void filterRecommended(Applicant* head, float passScore) {
    cout << "Recommended Applicants:" << endl;
    Applicant* temp = head;
    while (temp != nullptr) {
        if (temp->certificateScore >= passScore) {
            cout << "Surname: " << temp->surname << ", Certificate Score: " << temp->certificateScore << ", Education Document: " << temp->educationDocument << endl;
        }
        temp = temp->next;
    }
}

int main() {
    Applicant* head = nullptr;
    int n;
    cout << "Enter the number of applicants: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string surname, educationDocument;
        float certificateScore;
        cout << "Enter applicant's surname: ";
        cin >> surname;
        cout << "Enter applicant's certificate score: ";
        cin >> certificateScore;
        cout << "Enter type of education document (original/duplicate): ";
        cin >> educationDocument;
        addApplicant(head, surname, certificateScore, educationDocument);
    }

    cout << "Input List:" << endl;
    printList(head);

    float passScore;
    cout << "Enter the passing score: ";
    cin >> passScore;
    filterRecommended(head, passScore);

    return 0;
}
