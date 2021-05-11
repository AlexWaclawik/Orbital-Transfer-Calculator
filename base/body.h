// 2020-28-4
// body.h

#ifndef BODY_H_EXISTS
#define BODY_H_EXISTS

class Body {

	private:
		float MohoMu;
		float MohoAxis;
		float MohoSOI;
		float MohoVel;

		float EveMu;
		float EveAxis;
		float EveSOI;
		float EveVel;

		float KerbinMu;
		float KerbinAxis;
		float KerbinSOI;
		float KerbinVel;

		float DunaMu;
		float DunaAxis;
		float DunaSOI;
		float DunaVel;

		float DresMu;
		float DresAxis;
		float DresSOI;
		float DresVel;

		float JoolMu;
		float JoolAxis;
		float JoolSOI;
		float JoolVel;

		float EelooMu;
		float EelooAxis;
		float EelooSOI;
		float EelooVel;

	public:
		Body();

		static float getMohoMu();
		static float getMohoAxis();
		static float getMohoSOI();
		static float getMohoVel();

		static float getEveMu();
		static float getEveAxis();
		static float getEveSOI();
		static float getEveVel();

		static float getKerbinMu();
		static float getKerbinAxis();
		static float getKerbinSOI();
		static float getKerbinVel();

		static float getDunaMu();
		static float getDunaAxis();
		static float getDunaSOI();
		static float getDunaVel();

		static float getDresMu();
		static float getDresAxis();
		static float getDresSOI();
		static float getDresVel();

		static float getJoolMu();
		static float getJoolAxis();
		static float getJoolSOI();
		static float getJoolVel();

		static float getEelooMu();
		static float getEelooAxis();
		static float getEelooSOI();
		static float getEelooVel();
};
