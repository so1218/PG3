#include <Novice.h>

const char kWindowTitle[] = "LE2A_13_ホリ_ソウヘイ";

enum SceneType
{
	title,
	play,
	clear,
	none
};

class Input 
{
public:
	static Input* GetInstance()
	{
		static Input instance;
		return &instance;
	}

	void Update()
	{
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
	}

	bool Push(int key)
	{
		return keys[key] != 0;
	}

	bool Trigger(int key)
	{
		return preKeys[key] == 0 && keys[key] != 0;
	}

private:
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

class IScene 
{
public:
	virtual ~IScene() {}
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	SceneType GetNextScene() { return nextScene_; }

protected:
	SceneType nextScene_ = none;
};

class TitleScene : public IScene
{
public:
	void Init() override
	{
		nextScene_ = none;
	}

	void Update() override
	{
		if (Input::GetInstance()->Trigger(DIK_SPACE))
		{
			nextScene_ = play;
		}
	}

	void Draw() override
	{
		Novice::ScreenPrintf(600, 300, "Title Scene");
		Novice::ScreenPrintf(580, 320, "Press SPACE to Start");
	}
};

class PlayScene : public IScene
{
	struct Player 
	{
		int x, y;
		int w, h;
		int speed;
		bool isAlive;
	};

	struct Bullet 
	{
		int x, y;
		int w, h;
		int speed;
		bool isShot;
	};

	struct Enemy
	{
		int x, y;
		int w, h;
		int speed;
		bool isAlive;
	};

	Player player;
	Bullet bullet;
	Enemy enemy;

public:
	void Init() override 
	{
		nextScene_ = none;

		player = { 640, 600, 32, 32, 5, true };
		bullet = { 0, 0, 8, 16, 50, false };
		enemy = { 640, 100, 32, 32, 3, true };
	}

	void Update() override
	{
		if (Input::GetInstance()->Push(DIK_A) || Input::GetInstance()->Push(DIK_LEFT))
		{
			player.x -= player.speed;
		}
		if (Input::GetInstance()->Push(DIK_D) || Input::GetInstance()->Push(DIK_RIGHT))
		{
			player.x += player.speed;
		}

		if (!bullet.isShot)
		{
			if (Input::GetInstance()->Trigger(DIK_SPACE))
			{
				bullet.isShot = true;
				bullet.x = player.x + (player.w / 2) - (bullet.w / 2);
				bullet.y = player.y;
			}
		}
		else
		{
			bullet.y -= bullet.speed;
			if (bullet.y < -50)
			{
				bullet.isShot = false;
			}
		}

		if (enemy.isAlive)
		{
			enemy.x += enemy.speed;
			if (enemy.x <= 0 || enemy.x >= 1280 - enemy.w) 
			{
				enemy.speed *= -1;
			}

			if (bullet.isShot) 
			{
				if (bullet.x < enemy.x + enemy.w &&
					enemy.x < bullet.x + bullet.w &&
					bullet.y < enemy.y + enemy.h &&
					enemy.y < bullet.y + bullet.h)
				{

					enemy.isAlive = false; 
					bullet.isShot = false; 
				}
			}
		}

		if (!enemy.isAlive)
		{
			nextScene_ = clear;
		}
	}

	void Draw() override 
	{
		Novice::ScreenPrintf(10, 10, "AD:Move, SPACE:Shot");

		Novice::DrawBox(player.x, player.y, player.w, player.h, 0.0f, BLUE, kFillModeSolid);

		if (bullet.isShot)
		{
			Novice::DrawBox(bullet.x, bullet.y, bullet.w, bullet.h, 0.0f, WHITE, kFillModeSolid);
		}

		if (enemy.isAlive) 
		{
			Novice::DrawBox(enemy.x, enemy.y, enemy.w, enemy.h, 0.0f, RED, kFillModeSolid);
		}
	}
};

class ClearScene : public IScene 
{
public:
	void Init() override
	{
		nextScene_ = none;
	}

	void Update() override
	{
		if (Input::GetInstance()->Trigger(DIK_SPACE))
		{
			nextScene_ = title;
		}
	}

	void Draw() override 
	{
		Novice::ScreenPrintf(600, 300, "Clear");
		Novice::ScreenPrintf(580, 320, "Press SPACE to Title");
	}
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// 入力管理クラスのインスタンス取得
	Input* input = Input::GetInstance();

	IScene* currentScene = new TitleScene();
	currentScene->Init();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) 
	{
		// フレームの開始
		Novice::BeginFrame();

		///
		/// ↓更新処理ここから
		///

		input->Update();

		currentScene->Update();

		SceneType next = currentScene->GetNextScene();
		if (next != none)
		{
			delete currentScene;

			switch (next) 
			{
			case title:
				currentScene = new TitleScene();
				break;
			case play:
				currentScene = new PlayScene();
				break;
			case clear:
				currentScene = new ClearScene();
				break;
			}

			currentScene->Init();
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		currentScene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (input->Trigger(DIK_ESCAPE))
		{
			break;
		}
	}

	delete currentScene;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
