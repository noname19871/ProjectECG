#pragma once
#include <fstream>
#include <string>

namespace ProjectECG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:

		HelpForm(void) {

			InitializeComponent();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HelpForm() {
			if (components)
			{
				delete components;
			}
		}



	public: System::Windows::Forms::Label^ Information;

	private:
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Information = (gcnew System::Windows::Forms::Label());
			// 
			// DataButton
			// 
			this->Information->AutoSize = true;
			this->Information->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Information->Location = System::Drawing::Point(0, 0);
			this->Information->Margin = System::Windows::Forms::Padding(2);
			this->Information->Name = L"Information";
			this->Information->Size = System::Drawing::Size(this->Width, this->Height);
			this->Information->TabIndex = 1;

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1528, 761);
			this->Controls->Add(this->Information);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"HelpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"HelpForm";
			this->Load += gcnew System::EventHandler(this, &HelpForm::HelpForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void HelpForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
	}
		
	

	};
}