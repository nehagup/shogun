#ifndef _CFEATURES__H__
#define _CFEATURES__H__

#include "preproc/Preproc.h"

class CFeatures
{
	CFeatures();
	virtual ~CFeatures();

	/// get feature vector for sample num
	REAL* get_feature_vector(int num);
	
	/// set feature vector for sample num
	bool set_feature_vector(int num);

	/// get the pointer to the feature matrix
	/// num_feat,num_vectors are returned by reference
	REAL* get_feature_matrix(int &num_feat, int &num_vec);

	/** set feature matrix
		necessary to set feature_matrix, num_features, num_vectors, where
		num_features is the column offset, and columns are linear in memory
		see below for definition of feature_matrix
	*/
	virtual void set_feature_matrix()=0;
	
	/// set preprocessor
	void set_preproc(CPreProc* p);

	/// set current preprocessor
	CPreProc* get_preproc();

	/// Preprocess the feature feature_matrix
	bool preproc_feature_matrix();
	
protected:
	/// Preprocessor
	CPreProc* preproc;

	/** chunk of memory for all the feature_vectors	
	  it is aligned like 0...num_features-1 for vec0
	  0...num_features-1 for vec1 and so on up to vecnum_vectors-1
	  */
	REAL* feature_matrix;

	/// number of features in cache
	int num_features;

	/// number of vectors in cache
	int num_vectors;
};
#endif
