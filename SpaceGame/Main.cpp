/*****************************************************************************************
* Desc: Tutorial 02 IND_Surface
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Font.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

/*
==================
Main
==================
*/
int IndieLib()
{
	
	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance();
	if (!mI->init()) return 0;

	
	// ----- Surface loading -----

	IND_Surface *mRectangleSurf = IND_Surface::newSurface();
	mRectangleSurf->setGrid(mI->_window->getWidth() - 1, mI->_window->getHeight() - 1);

	// Loading Background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/new-bg.png", IND_OPAQUE, IND_32)) return 0;

	// Loading sprite of a star
	IND_Surface *mSurfaceAsteroid = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceAsteroid, "../SpaceGame/resources/asteroid.png", IND_ALPHA, IND_32)) return 0;

	IND_Font *mFontSmall = IND_Font::newFont();
	if (!mI->_fontManager->add(mFontSmall, "../SpaceGame/resources/font_small.png", "../SpaceGame/resources/font_small.xml", IND_ALPHA, IND_32)) return 0;

	// ----- Animations loading -----

	//if (!mI->_animationManager->addToSurface(mSwordMasterAnimation, "../../resources/animations/sword_master.xml", IND_ALPHA, IND_16, 0, 255, 0)) return 0; //TODO: setAlpha in Ind_Image fails.
	// Characters animations, we apply a color key of (0, 48, 152)
	//IND_Animation *mAnimationCharacter1 = IND_Animation::newAnimation();
	// if (!mI->_animationManager->addToSurface(mAnimationCharacter1, "../SpaceGame/resources/animations/character1.xml", IND_ALPHA, IND_32, 0, 48, 152)) return 0;
	//if (!mI->_animationManager->addToSurface(mAnimationCharacter1, "../SpaceGame/resources/animations/character1.xml", IND_ALPHA, IND_32, 0, 255, 0)) return 0; //TODO: setAlpha in Ind_Image fails.
	// Loading Beetleship
	IND_Surface *mSurfaceBeetle = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBeetle, "../SpaceGame/resources/beetleship.png", IND_ALPHA, IND_32)) return 0;

	// Sword Master animation, we apply a color key of (0, 255, 0)
	//IND_Animation *mSwordMasterAnimation = IND_Animation::newAnimation();
	//if (!mI->_animationManager->addToSurface(mSwordMasterAnimation, "../SpaceGame/resources/animations/sword_master.xml", IND_ALPHA, IND_16, 0, 255, 0)) return 0; //TODO: setAlpha in Ind_Image fails.

	// ----- Set the surface and animations into 2d entities -----

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	// Rectangle
	IND_Entity2d *mRectangle = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mRectangle);
	mRectangle->setPrimitive2d(IND_RECTANGLE);
	mRectangle->setRectangle(1, 1, mI->_window->getWidth() - 1, mI->_window->getHeight() - 1);
	mRectangle->setSurface(mRectangleSurf);

	int lifes = 3;

	// Asteroid
	IND_Entity2d *asteroid = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(asteroid);
	asteroid->setSurface(mSurfaceAsteroid);

	// Asteroid 2
	IND_Entity2d *asteroid2 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(asteroid2);
	asteroid2->setSurface(mSurfaceAsteroid);

	// Asteroid 3
	IND_Entity2d *asteroid3 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(asteroid3);
	asteroid3->setSurface(mSurfaceAsteroid);

	// Character 1
	//IND_Entity2d *mPlayer1 = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mPlayer1);					// Entity adding
	//mPlayer1->setAnimation(mAnimationCharacter1);				// Set the animation into the entity

	// Creating 2d entity for the Beetleship
	IND_Entity2d *mBeetle = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBeetle);					// Entity adding
	mBeetle->setSurface(mSurfaceBeetle);					// Set the surface into the entity

	// Text small white
	IND_Entity2d *mTextSmallWhite = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mTextSmallWhite);				// Entity adding
	mTextSmallWhite->setFont(mFontSmall);					// Set the font into the entity

	// Creating 2d entity for the Sword Master animation
	//IND_Entity2d *mSwordMaster = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mSwordMaster);				// Entity adding
	//mSwordMaster->setAnimation(mSwordMasterAnimation);			// Set the animation into the entity

	// ----- Changing the attributes of the 2d entities -----

	// Beetle
	mBeetle->setHotSpot(0.5f, 0.5f);
	mBeetle->setMirrorX(1);
	mBeetle->setBoundingTriangle("beetle_head", 160, 105, 160, 170, 190, 135);
	mBeetle->setBoundingCircle("beetle_boy_head", 85, 52, 55);
	mBeetle->setBoundingRectangle("beetle_boy_body", 20, 100, 140, 100);
	int height = mI->_window->getHeight();
	int width = mI->_window->getWidth();

	// Player 1
	//mPlayer1->setSequence(0);						// Choose sequence
	//mPlayer1->setPosition(140, 200, 0);
	//mPlayer1->setMirrorX(1);						// Horizontal
	//mPlayer1->setBoundingRectangle("hero", 1, 1, 116, 198);
	

	// Rectangle
	//mRectangle->setRectangle(1, 1, mI->_window->getWidth() - 1, mI->_window->getHeight() - 1);
	mRectangle->setTint(187, 56, 29);
	mRectangle->setBoundingRectangle("up", 1, 1, width - 1, 2);
	mRectangle->setBoundingRectangle("down", 1, height - 2, mI->_window->getWidth() - 1, height-1);
	mRectangle->setBoundingRectangle("left", 1, 1, 2, height - 1);
	mRectangle->setBoundingRectangle("right", width - 2, 1, 1, height - 1);

	// asteroid->setBoundingRectangle("whole", 1, 1, 96, 96);

	// Text
	mTextSmallWhite->setLineSpacing(18);
	mTextSmallWhite->setCharSpacing(-7);
	mTextSmallWhite->setPosition(400, 30, 10);
	mTextSmallWhite->setAlign(IND_RIGHT);

	// Sword Master Animation
	//mSwordMaster->setHotSpot(0.5f, 0.5f);
	//mSwordMaster->setPosition(400, 220, 3);

	// asteroid
	asteroid->setPosition(mI->_window->getWidth() - mSurfaceAsteroid->getWidth(), 0, 100);
	asteroid2->setPosition(mI->_window->getWidth() - 2 * mSurfaceAsteroid->getWidth(), 0, 100);
	asteroid3->setPosition(mI->_window->getWidth() - 3 * mSurfaceAsteroid->getWidth(), 0, 100);
	// ----- Main Loop -----
	float mXPos = 400;
	float mYPos = height - 250;
	float mSpeed = 200;
	float acceleration = 0.5;
	float mDelta;

	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{
		mI->_input->update();

		mDelta = mI->_render->getFrameTime() / 1000.0f;

		bool dPressed = mI->_input->isKeyPressed(IND_D);
		bool aPressed = mI->_input->isKeyPressed(IND_A);
		bool wPressed = mI->_input->isKeyPressed(IND_W);
		bool sPressed = mI->_input->isKeyPressed(IND_S);
		if (dPressed){
			mXPos += mSpeed * mDelta;
		}
		if (aPressed){
			mXPos -= mSpeed * mDelta;
		}
		if (sPressed){
			mYPos += mSpeed * mDelta;
		}
		if (wPressed){
			mYPos -= mSpeed * mDelta;
		}

		if(!dPressed && !aPressed && !sPressed && !wPressed){
			mSpeed = 200;
		}else if(
			mSpeed < 700 &&
			(
			(dPressed && !aPressed)
			|| (sPressed && !wPressed)
			|| (!dPressed && aPressed)
			|| (!sPressed && wPressed)
			)){
			mSpeed += acceleration;
		}

		//mPlayer1->setAngleXYZ(0, 0, (float)mPos);

//		mAngle += mSpeedRotation * mDelta;

/*		if (mScale < 0){
			mScale = 0;
		}*/

		// ----- Updating entities attributes  -----

		/*mBack->setAngleXYZ(0, 0, -mAngle);
		mPlayer1->setAngleXYZ(0, 0, mAngle);
		mPlayer1->setScale(mScale, mScale);*/

		// ----- Check collisions -----

		//mTextSmallWhite->setText("No collision between the groups we are checking");

		/*if (mI->_entity2dManager->isCollision(mPlayer1, "beetle_boy_head", mSwordMaster, "sword")){
			mTextSmallWhite->setText("Collision between beetle boy head and the sword");
		}*/
		mTextSmallWhite->setText("No collision between the groups we are checking");

		if (mI->_entity2dManager->isCollision(mBeetle, "*", mRectangle, "*")){
				mTextSmallWhite->setText("Collision PLAYER and RECTANGLE");
				if (lifes >= 3)
				{
					lifes = 2;
					asteroid3->setShow(false);
				}
				else if (lifes == 2)
				{
					lifes = 1;
					asteroid2->setShow(false);
				}else{
					lifes = 3;
					asteroid2->setShow(true);
					asteroid3->setShow(true);
				}
				mXPos = 400;
				mYPos = height - 250;
				mBeetle->setPosition(mXPos, mYPos, 1);
				
		}else{
			mBeetle->setPosition((float)mXPos, mYPos, 1);
		}

		//if (mI->_entity2dManager->isCollision(mBeetle, "*", star, "*")){
		//	mTextSmallWhite->setText("Collision between PLAYER and STAR");
		//}

		//if (mI->_entity2dManager->isCollision(mBeetle, "*", mSwordMaster, "sword")){
		//	mTextSmallWhite->setText("Collision PLAYER and SWORD");
		//}

		// ----- Render  -----

		mI->_render->beginScene();
		mI->_render->clearViewPort(0, 0, 0);
		mI->_entity2dManager->renderEntities2d();
		mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255);
		mI->_render->endScene();
	}

	// ----- Free -----

	mI->end();

	return 0;
}