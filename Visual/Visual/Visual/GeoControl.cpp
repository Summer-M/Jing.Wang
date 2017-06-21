#include "GeoControl.h"

namespace Visual
{
	System::Void GeoControl::pictureBox1_Paint( System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e )
	{
		mygraphics = e->Graphics;
		mygraphics->DrawImage(bitmap, 0, 0);
	}

	void GeoControl::AboutMatrix()
	{
		VisualPaint::TPoint Pt(100, 100, this->pictureBox1->Width, this->pictureBox1->Height);
		Pt.paint(mygraphics, brush, Pt.X(), Pt.Y(), 15.0);
	}

	void GeoControl::change()
	{
		;
	}

	System::Void GeoControl::button1_Click( System::Object^  sender, System::EventArgs^  e )
	{
		if (this->Model->SelectedIndex == 0)
			AboutMatrix();
		else if (this->Model->SelectedIndex == 1)
			AboutMatrix();
		else if (this->Model->SelectedIndex == 2)
			AboutMatrix();

		this->pictureBox1->Invalidate();
	}

	System::Void GeoControl::GeoControl_Load( System::Object^  sender, System::EventArgs^  e )
	{
		mygraphics->FromImage(bitmap);
		this->pictureBox1->Invalidate();
	}
}