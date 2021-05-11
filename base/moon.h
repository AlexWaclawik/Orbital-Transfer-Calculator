// 2020-28-4
// moon.h

#ifndef MOON_H_EXISTS
#define MOON_H_EXISTS

class Moon {

	private:

		float GillyMu;
		float GillyAxis;
		float GillySOI;
		float GillyVel;

		float MunMu;
		float MunAxis;
		float MunSOI;
		float MunVel;

		float MinmusMu;
		float MinmusAxis;
		float MinmusSOI;
		float MinmusVel;

		float IkeMu;
		float IkeAxis;
		float IkeSOI;
		float IkeVel;

		float LaytheMu;
		float LaytheAxis;
		float LaytheSOI;
		float LaytheVel;

		float VallMu;
		float VallAxis;
		float VallSOI;
		float VallVel;

		float TyloMu;
		float TyloAxis;
		float TyloSOI;
		float TyloVel;

		float BopMu;
		float BopAxis;
		float BopSOI;
		float BopVel;

		float PolMu;
		float PolAxis;
		float PolSOI;
		float PolVel;		

	public:
		
		Moon();

		static float getGillyMu();
		static float getGillyAxis();
		static float getGillySOI();
		static float getGillyVel();

		static float getMunMu();
		static float getMunAxis();
		static float getMunSOI();
		static float getMunVel();

		static float getMinmusMu();
		static float getMinmusAxis();
		static float getMinmusSOI();
		static float getMinmusVel();

		static float getIkeMu();
		static float getIkeAxis();
		static float getIkeSOI();
		static float getIkeVel();

		static float getLaytheMu();
		static float getLaytheAxis();
		static float getLaytheSOI();
		static float getLaytheVel();

		static float getVallMu();
		static float getVallAxis();
		static float getVallSOI();
		static float getVallVel();

		static float getTyloMu();
		static float getTyloAxis();
		static float getTyloSOI();
		static float getTyloVel();

		static float getBopMu();
		static float getBopAxis();
		static float getBopSOI();
		static float getBopVel();

		static float getPolMu();
		static float getPolAxis();
		static float getPolSOI();
		static float getPolVel();


};
