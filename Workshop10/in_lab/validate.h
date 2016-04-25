#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H


namespace sict{
	template<typename VT>
	bool validate(VT const & minimum, VT const &  maximum, const VT* testValue,int testelements, bool * validateResults){
	       int i;
		bool flag = true;
		for (i = 0; i < testelements; i++){
			if (testValue[i] >= minimum && maximum >= testValue[i]){
				validateResults[i] = true;
			}
			else{
				validateResults[i] = false;
				flag = false;
			}
		
		}
		return flag;
	}
}

#endif
