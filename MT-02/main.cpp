#include <Novice.h>

const char kWindowTitle[] = "学籍番号";

struct Matrix2x2 {
	float m[2][2];
};

struct Matrix3x3 {
	float m[3][3];
};

struct Matrix4x4 {
	float m[4][4];
};

static const int kRowHeigth = 20;
static const int kColumWidth = 60;

void MatrixScrennPrint(int x, int y, const Matrix4x4& matrix,const char* label) {

	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; row++) {
		for (int colum = 0; colum < 4; colum++) {
			Novice::ScreenPrintf(x + colum * kColumWidth, y + (row + 1) * kRowHeigth, "%6.02f", matrix.m[row][colum]);
		}
	}
}

Matrix4x4 Add(Matrix4x4 m1, Matrix4x4 m2) {
	Matrix4x4 answer;
	for (int row = 0; row < 4; row++) {
		for (int colum = 0; colum < 4; colum++) {
			answer.m[row][colum] = m1.m[row][colum] + m2.m[row][colum];
		}
	}

	return answer;
}

Matrix4x4 Sub(Matrix4x4 m1, Matrix4x4 m2) {
	Matrix4x4 answer;
	for (int row = 0; row < 4; row++) {
		for (int colum = 0; colum < 4; colum++) {
			answer.m[row][colum] = m1.m[row][colum] - m2.m[row][colum];
		}
	}

	return answer;
}

Matrix4x4 Multi(Matrix4x4 m1, Matrix4x4 m2) {
	Matrix4x4 answer;

	answer.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] +
					 m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0] ;
	answer.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] +
					 m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	answer.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] +
					 m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	answer.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] +
					 m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	answer.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] +
					 m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	answer.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] +
					 m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	answer.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] +
					 m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	answer.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] +
					 m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	answer.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] +
					 m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	answer.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] +
					 m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	answer.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] +
					 m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	answer.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] +
					 m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	answer.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] +
					 m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	answer.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] +
					 m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	answer.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] +
					 m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	answer.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] +
					 m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];

	return answer;
 }

Matrix4x4 Invers(Matrix4x4 m1) {

	float ImversA =
		m1.m[0][0] * m1.m[1][1] * m1.m[2][2] * m1.m[3][3] +
		m1.m[0][0] * m1.m[1][2] * m1.m[2][3] * m1.m[3][1] +
		m1.m[0][0] * m1.m[1][3] * m1.m[2][1] * m1.m[3][2] -
		m1.m[0][0] * m1.m[1][3] * m1.m[2][2] * m1.m[3][1] -
		m1.m[0][0] * m1.m[1][2] * m1.m[2][1] * m1.m[3][3] -
		m1.m[0][0] * m1.m[1][1] * m1.m[2][3] * m1.m[3][2] -
		m1.m[0][1] * m1.m[1][0] * m1.m[2][2] * m1.m[3][3] -
		m1.m[0][2] * m1.m[1][0] * m1.m[2][3] * m1.m[3][1] -
		m1.m[0][3] * m1.m[1][0] * m1.m[2][1] * m1.m[3][2] +
		m1.m[0][3] * m1.m[1][0] * m1.m[2][2] * m1.m[3][1] +
		m1.m[0][2] * m1.m[1][0] * m1.m[2][1] * m1.m[3][3] +
		m1.m[0][1] * m1.m[1][0] * m1.m[2][3] * m1.m[3][2] +
		m1.m[0][1] * m1.m[1][2] * m1.m[2][0] * m1.m[3][3] +
		m1.m[0][2] * m1.m[1][3] * m1.m[2][0] * m1.m[3][1] +
		m1.m[0][3] * m1.m[1][1] * m1.m[2][0] * m1.m[3][2] -
		m1.m[0][3] * m1.m[1][2] * m1.m[2][0] * m1.m[3][1] -
		m1.m[0][2] * m1.m[1][1] * m1.m[2][0] * m1.m[3][3] -
		m1.m[0][1] * m1.m[1][3] * m1.m[2][0] * m1.m[3][2] -
		m1.m[0][1] * m1.m[1][2] * m1.m[2][3] * m1.m[3][0] -
		m1.m[0][2] * m1.m[1][3] * m1.m[2][1] * m1.m[3][0] -
		m1.m[0][3] * m1.m[1][1] * m1.m[2][2] * m1.m[3][0] +
		m1.m[0][3] * m1.m[1][2] * m1.m[2][1] * m1.m[3][0] +
		m1.m[0][2] * m1.m[1][1] * m1.m[2][3] * m1.m[3][0] +
		m1.m[0][1] * m1.m[1][3] * m1.m[2][2] * m1.m[3][0];

	float InversA = 1 / ImversA;

	Matrix4x4 answer;
	answer.m[0][0] = InversA *
		   (m1.m[1][1] * m1.m[2][2] * m1.m[3][3] +
			m1.m[1][2] * m1.m[2][3] * m1.m[3][1] +
			m1.m[1][3] * m1.m[2][1] * m1.m[3][2] -
			m1.m[1][3] * m1.m[2][2] * m1.m[3][1] -
			m1.m[1][2] * m1.m[2][1] * m1.m[3][3] -
			m1.m[1][1] * m1.m[2][3] * m1.m[3][2]);

	answer.m[0][1] = InversA *
		   (m1.m[0][3] * m1.m[2][2] * m1.m[3][1] +
			m1.m[0][2] * m1.m[2][1] * m1.m[3][3] +
			m1.m[0][1] * m1.m[2][3] * m1.m[3][2] -
			m1.m[0][1] * m1.m[2][2] * m1.m[3][3] -
			m1.m[0][2] * m1.m[2][3] * m1.m[3][1] -
			m1.m[0][3] * m1.m[2][1] * m1.m[3][2]);

	answer.m[0][2] = InversA *
		   (m1.m[0][1] * m1.m[1][2] * m1.m[3][3] +
			m1.m[0][2] * m1.m[1][3] * m1.m[3][1] +
			m1.m[0][3] * m1.m[1][1] * m1.m[3][2] -
			m1.m[0][3] * m1.m[1][2] * m1.m[3][1] -
			m1.m[0][2] * m1.m[1][1] * m1.m[3][3] -
			m1.m[0][1] * m1.m[1][3] * m1.m[3][2]);

	answer.m[0][3] = InversA *
		   (m1.m[0][3] * m1.m[1][2] * m1.m[2][1] +
			m1.m[0][2] * m1.m[1][1] * m1.m[2][3] +
			m1.m[0][1] * m1.m[1][3] * m1.m[2][2] -
			m1.m[0][1] * m1.m[1][2] * m1.m[2][3] -
			m1.m[0][2] * m1.m[1][3] * m1.m[2][1] -
			m1.m[0][3] * m1.m[1][1] * m1.m[2][2]);

	answer.m[1][0] = InversA *
		   (m1.m[1][3] * m1.m[2][2] * m1.m[3][0] +
			m1.m[1][2] * m1.m[2][0] * m1.m[3][3] +
			m1.m[1][0] * m1.m[2][3] * m1.m[3][2] -
			m1.m[1][0] * m1.m[2][2] * m1.m[3][3] -
			m1.m[1][2] * m1.m[2][3] * m1.m[3][0] -
			m1.m[1][3] * m1.m[2][0] * m1.m[3][2]);

	answer.m[1][1] = InversA *
		   (m1.m[0][0] * m1.m[2][2] * m1.m[3][3] +
			m1.m[0][2] * m1.m[2][3] * m1.m[3][0] +
			m1.m[0][3] * m1.m[2][0] * m1.m[3][2] -
			m1.m[0][3] * m1.m[2][2] * m1.m[3][0] -
			m1.m[0][2] * m1.m[2][0] * m1.m[3][3] -
			m1.m[0][0] * m1.m[2][3] * m1.m[3][2]);

	answer.m[1][2] = InversA *
		   (m1.m[0][3] * m1.m[1][2] * m1.m[3][0] +
			m1.m[0][2] * m1.m[1][0] * m1.m[3][3] +
			m1.m[0][0] * m1.m[1][3] * m1.m[3][2] -
			m1.m[0][0] * m1.m[1][2] * m1.m[3][3] -
			m1.m[0][2] * m1.m[1][3] * m1.m[3][0] -
			m1.m[0][3] * m1.m[1][0] * m1.m[3][2]);

	answer.m[1][3] = InversA *
		   (m1.m[0][0] * m1.m[1][2] * m1.m[2][3] +
		 	m1.m[0][2] * m1.m[1][3] * m1.m[2][0] +
			m1.m[0][3] * m1.m[1][0] * m1.m[2][2] -
			m1.m[0][3] * m1.m[1][2] * m1.m[2][0] -
			m1.m[0][2] * m1.m[1][0] * m1.m[2][3] -
			m1.m[0][0] * m1.m[1][3] * m1.m[2][2]);

	answer.m[2][0] = InversA *
		   (m1.m[1][0] * m1.m[2][1] * m1.m[3][3] +
			m1.m[1][1] * m1.m[2][3] * m1.m[3][0] +
			m1.m[1][3] * m1.m[2][0] * m1.m[3][1] -
			m1.m[1][3] * m1.m[2][1] * m1.m[3][0] -
			m1.m[1][1] * m1.m[2][0] * m1.m[3][3] -
			m1.m[1][0] * m1.m[2][3] * m1.m[3][1]);

	answer.m[2][1] = InversA *
		   (m1.m[0][3] * m1.m[2][1] * m1.m[3][0] +
			m1.m[0][1] * m1.m[2][0] * m1.m[3][3] +
			m1.m[0][0] * m1.m[2][3] * m1.m[3][1] -
			m1.m[0][0] * m1.m[2][1] * m1.m[3][3] -
			m1.m[0][1] * m1.m[2][3] * m1.m[3][0] -
			m1.m[0][3] * m1.m[2][0] * m1.m[3][1]);

	answer.m[2][2] = InversA *
		   (m1.m[0][0] * m1.m[1][1] * m1.m[3][3] +
			m1.m[0][1] * m1.m[1][3] * m1.m[3][0] +
			m1.m[0][3] * m1.m[1][0] * m1.m[3][1] -
			m1.m[0][3] * m1.m[1][1] * m1.m[3][0] -
			m1.m[0][1] * m1.m[1][0] * m1.m[3][3] -
			m1.m[0][0] * m1.m[1][3] * m1.m[3][1]);

	answer.m[2][3] = InversA *
		(m1.m[0][3] * m1.m[1][1] * m1.m[2][0] +
			m1.m[0][1] * m1.m[1][0] * m1.m[2][3] +
			m1.m[0][0] * m1.m[1][3] * m1.m[2][1] -
			m1.m[0][0] * m1.m[1][1] * m1.m[2][3] -
			m1.m[0][1] * m1.m[1][3] * m1.m[2][0] -
			m1.m[0][3] * m1.m[1][0] * m1.m[2][1]);

	answer.m[3][0] = InversA *
		(m1.m[1][2] * m1.m[2][1] * m1.m[3][0] +
			m1.m[1][1] * m1.m[2][0] * m1.m[3][2] +
			m1.m[1][0] * m1.m[2][2] * m1.m[3][1] -
			m1.m[1][0] * m1.m[2][1] * m1.m[3][2] -
			m1.m[1][1] * m1.m[2][2] * m1.m[3][0] -
			m1.m[1][2] * m1.m[2][0] * m1.m[3][1]); 

	answer.m[3][1] = InversA *
		   (m1.m[0][0] * m1.m[2][1] * m1.m[3][2] +
			m1.m[0][1] * m1.m[2][2] * m1.m[3][0] +
			m1.m[0][2] * m1.m[2][0] * m1.m[3][1] -
			m1.m[0][2] * m1.m[2][1] * m1.m[3][0] -
			m1.m[0][1] * m1.m[2][0] * m1.m[3][2] -
			m1.m[0][0] * m1.m[2][2] * m1.m[3][1]);

	answer.m[3][2] = InversA *
		   (m1.m[0][2] * m1.m[1][1] * m1.m[3][0] +
			m1.m[0][1] * m1.m[1][0] * m1.m[3][2] +
			m1.m[0][0] * m1.m[1][2] * m1.m[3][1] -
			m1.m[0][0] * m1.m[1][1] * m1.m[3][2] -
			m1.m[0][1] * m1.m[1][2] * m1.m[3][0] -
			m1.m[0][2] * m1.m[1][0] * m1.m[3][1]);

	answer.m[3][3] = InversA *
		(m1.m[0][0] * m1.m[1][1] * m1.m[2][2] +
			m1.m[0][1] * m1.m[1][2] * m1.m[2][0] +
			m1.m[0][2] * m1.m[1][0] * m1.m[2][1] -
			m1.m[0][2] * m1.m[1][1] * m1.m[2][0] -
			m1.m[0][1] * m1.m[1][0] * m1.m[2][2] -
			m1.m[0][0] * m1.m[1][2] * m1.m[2][1]);
		
	return answer;
}

Matrix4x4 indetry() {
	Matrix4x4 m1 = { 1.0f,0.0f,0.0f,0.0f,
					 0.0f,1.0f,0.0f,0.0f,
					 0.0f,0.0f,1.0f,0.0f,
					 0.0f,0.0f,0.0f,1.0f };

	return m1;
}

Matrix4x4 Transpose(Matrix4x4 m1) {
	Matrix4x4 answer;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			answer.m[i][j] = m1.m[j][i];
		}
	}

	return answer;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Matrix4x4 m1 = { 3.2f,0.7f,9.6f,4.4f,
					 5.5f,1.3f,7.8f,2.1f,
					 6.9f,8.0f,2.6f,1.0f,
					 0.5,7.2f,5.1f,3.3f };

	Matrix4x4 m2 = { 4.1f,6.5f,3.3f,2.2f,
					 8.8f,0.6f,9.9f,7.7f,
					 1.1f,5.5f,6.6f,0.0f,
					 3.3f,9.9f,8.8f,2.2f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Matrix4x4 resltAdd = Add(m1, m2);
		Matrix4x4 resltSub = Sub(m1, m2);
		Matrix4x4 resultMulti = Multi(m1, m2);
		Matrix4x4 inverseM1 = Invers(m1);
		Matrix4x4 inverseM2 = Invers(m2);
		Matrix4x4 transposeM1 = Transpose(m1);
		Matrix4x4 transposeM2 = Transpose(m2);
		Matrix4x4 identry = indetry();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScrennPrint(0, 0, resltAdd, "Add");
		MatrixScrennPrint(0, kRowHeigth * 5, resltSub, "Subtract");
		MatrixScrennPrint(0, kRowHeigth * 10, resultMulti, "Mltiply");
		MatrixScrennPrint(0, kRowHeigth * 15, inverseM1, "inverseM1");
		MatrixScrennPrint(0, kRowHeigth * 20,inverseM2,"inverseM2");

		MatrixScrennPrint(kColumWidth * 5, 0, transposeM1, "transposeM1");
		MatrixScrennPrint(kColumWidth * 5, kRowHeigth * 5, transposeM2, "transposeM2");
		MatrixScrennPrint(kColumWidth * 5, kRowHeigth * 10, identry, "indetry");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
