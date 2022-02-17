#pragma once
#include <string>
#include <string>
#include <regex>
#include <msclr\marshal_cppstd.h>
using namespace std;

namespace unit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	class pointers {
		private :
			double x, y;
		public:
			double get_x()
			{
				return x;
			}
			double get_y()
			{
				return y;
			}
			void set_values(double x, double y)
			{
				this->x = x;
				this->y = y;
			}
	};
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
		}

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();

			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;

			this->textBox2->Location = System::Drawing::Point(12, 38);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;

			this->textBox3->Location = System::Drawing::Point(12, 64);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;

			this->button1->Location = System::Drawing::Point(12, 90);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);

			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(44, 168);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";

			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Sin2a", L"R" });
			this->checkedListBox1->Location = System::Drawing::Point(12, 119);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(100, 34);
			this->checkedListBox1->TabIndex = 6;

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(127, 195);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		pointers getValues(string str) {
			pointers _tmp;
			double numbers[2] = {};
			static const std::regex rdelim{ "," };
			int i = 0;
			std::vector<std::string> strPairs{
					std::sregex_token_iterator(str.begin(), str.end(), rdelim, -1),
					std::sregex_token_iterator()
			};
			for (std::vector<string>::iterator it = std::begin(strPairs); it != std::end(strPairs); ++it) {
				numbers[i] = std::stod(*it);
				i++;
			}
			_tmp.set_values(numbers[0], numbers[1]);
			return _tmp;
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			if (sizeof(textBox1->Text) == 0 || sizeof(textBox2->Text) == 0 || sizeof(textBox2->Text) == 0) {
				MessageBox::Show("Пустые данные!", "Ок", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else {
				pointers a, b, c;
				a = getValues(msclr::interop::marshal_as<std::string>(textBox1->Text));
				b = getValues(msclr::interop::marshal_as<std::string>(textBox2->Text));
				c = getValues(msclr::interop::marshal_as<std::string>(textBox3->Text));
				System::String^ managedString = "a : x " + a.get_x() + " y " + a.get_y();
				label1->Text = managedString;
				checkedListBox1->CheckedItems;
				if (checkedListBox1->GetItemChecked(0)) {
					double cos = (a.get_x() * b.get_x() + a.get_y() * b.get_y()) / (sqrt(pow(a.get_x(), 2) + pow(a.get_y(), 2) * (sqrt(pow(b.get_x(), 2) + pow(b.get_y(), 2)))));
					managedString = cos.ToString();
					label1->Text = managedString;
					//some staff
				}
			}
		}
	};
}
