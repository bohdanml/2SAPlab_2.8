#include "pch.h"
#include "CppUnitTest.h"
#include "..//2SAPlab_2.8/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {

            Applicant* head = nullptr;
            addApplicant(head, "Doe", 95.5f, "original");
            Assert::IsNotNull(head);
            Assert::AreEqual("Doe", head->surname.c_str());
            Assert::AreEqual(95.5f, head->certificateScore);
            Assert::AreEqual("original", head->educationDocument.c_str());
            Assert::IsNull(head->next);
            Assert::IsNull(head->prev);
            delete head;


        }
    };
}
