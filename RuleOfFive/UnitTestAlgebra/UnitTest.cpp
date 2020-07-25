#include "pch.h"
#include "CppUnitTest.h"
#include "../algebra/Header/quadrilateral.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAlgebra
{
    TEST_CLASS(UnitTest1)
    {
    public:
		
        TEST_METHOD(TestMethodConstructor)
        {
			wchar_t ar1[7]  = L"Einari";
			wchar_t ar2[5] = L"Irma";
			quadrilateral a;
			a.SetBase(5);
			a.SetHeight(10);
			a.SetName(ar1, 7);

			quadrilateral b(a);
			int cmp = wcscmp(b.GetName(), a.GetName());
			//b created from a all values must be same
			Assert::AreEqual(cmp, 0);

			a.SetName(ar2, 5);
			cmp = wcscmp(b.GetName(), a.GetName());
			//a name changed after creating b. Names should be different.
			Assert::AreNotEqual(cmp, 0);

        }

		TEST_METHOD(TestMethodAssignmentOperator)
		{
			wchar_t ar1[7] = L"Einari";
			wchar_t ar2[5] = L"Irma";
			quadrilateral a;
			a.SetBase(5);
			a.SetHeight(10);
			a.SetName(ar1,7);
			quadrilateral b = a;
			//b created from a all values must be same
			int cmp = wcscmp(b.GetName(), a.GetName());
			Assert::AreEqual(cmp, 0);
			b.SetName(ar2,5);
			//b name changed after creating b. Names should be different.
			cmp = wcscmp(b.GetName(), a.GetName());
			Assert::AreNotEqual(cmp, 0);
		}

		TEST_METHOD(TestMethodSelfAssignmentCheck)
		{
			quadrilateral a;
			quadrilateral* p = &a;
			a = *p;
			//How to check?
		}

		TEST_METHOD(TestMethodHeap)
		{
			wchar_t ar1[7] = L"Einari";
			wchar_t ar2[5] = L"Irma";
			quadrilateral * a;
			a = new quadrilateral();
			a->SetBase(10);
			a->SetHeight(5);
			a->SetName(ar1, 7);
			quadrilateral * b = new quadrilateral(*a);

			
			int cmp = wcscmp(b->GetName(), a->GetName());
			Assert::AreEqual(cmp, 0);
			a->SetName(ar2, 5);
			cmp = wcscmp(b->GetName(), a->GetName());
			Assert::AreNotEqual(cmp, 0);

		}

		TEST_METHOD(TestMethodMoveConstructor)
		{
			wchar_t ar1[7] = L"Einari";
			wchar_t ar2[5] = L"Irma";
			quadrilateral a;
			a.SetBase(5);
			a.SetHeight(10);
			a.SetName(ar1, 7);
			quadrilateral b = std::move(a);
			
			wchar_t const * name = b.GetName();
			int cmp = wcscmp(ar1, name);
			Assert::AreEqual(cmp, 0);
			Assert::AreEqual(a.GetName(), nullptr);

		}

		TEST_METHOD(TestMethodMoveAssignmentOperator)
		{
			wchar_t ar1[7] = L"Einari";
			wchar_t ar2[5] = L"Irma";
			quadrilateral a;
			a.SetBase(5);
			a.SetHeight(10);
			a.SetName(ar1, 7);
			quadrilateral b;
			b = std::move(a);
			wchar_t const * name = b.GetName();
			int cmp = wcscmp(ar1, name);
			Assert::AreEqual(cmp, 0);
			Assert::AreEqual(a.GetName(), nullptr);

		}
    };
}