/*
 * Restructuring Shogun's statistical hypothesis testing framework.
 * Copyright (C) 2016  Soumyajit De
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef B_TEST_MMD_H_
#define B_TEST_MMD_H_

#include <shogun/statistical_testing/StreamingMMD.h>

namespace shogun
{

class CBTestMMD : public CStreamingMMD
{
public:
	typedef std::function<float32_t(SGMatrix<float32_t>)> operation;
	CBTestMMD();
	virtual ~CBTestMMD();

	void set_blocksize(index_t blocksize);
	void set_num_blocks_per_burst(index_t num_blocks_per_burst);

	virtual float64_t compute_p_value(float64_t statistic);
	virtual float64_t compute_threshold(float64_t alpha);

	virtual const char* get_name() const;
private:
	virtual const operation get_direct_estimation_method() const;
	virtual float64_t normalize_statistic(float64_t statistic) const;
	virtual const float64_t normalize_variance(float64_t variance) const;
};

}
#endif // B_TEST_MMD_H_
