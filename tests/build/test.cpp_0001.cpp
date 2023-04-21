#include "ucenv.h"

extern "C" void calcCoef_x(const InputDF &, const InputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &); // as calcCoef_x
extern "C" void calcCoef_y(const InputDF &, const InputDF &, const InputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &); // as calcCoef_y
extern "C" void calcCoef_z(const InputDF &, const InputDF &, const InputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &); // as calcCoef_z
extern "C" void calcVal(int, int, int, const InputDF &, const InputDF &, const InputDF &, OutputDF &, OutputDF &, const InputDF &); // as calcVal
extern "C" void calccoef_pr_x(int, int, int, const InputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &, OutputDF &, OutputDF &, const InputDF &, OutputDF &); // as calccoef_pr_x
extern "C" void calccoef_pr_y(int, int, const InputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &, OutputDF &, OutputDF &, const InputDF &, OutputDF &); // as calccoef_pr_y
extern "C" void calccoef_pr_z(int, int, const InputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &, OutputDF &, OutputDF &, const InputDF &, OutputDF &); // as calccoef_pr_z
extern "C" void copy_vector(const InputDF &, OutputDF &); // as copy_v
extern "C" void fill_u(int, int, const InputDF &, const InputDF &, OutputDF &); // as fill_u
extern "C" void gather_arr(const InputDF &, const InputDF &, OutputDF &); // as gather_arr
extern "C" void getFG_Size(const char *, OutputDF &, OutputDF &, OutputDF &, OutputDF &); // as getFG_Size
extern "C" void initconst(const InputDF &, OutputDF &, OutputDF &, OutputDF &); // as initConst
extern "C" void init_alfa_beta(int, OutputDF &); // as init_alfa_beta
extern "C" void init_uend(int, OutputDF &); // as init_uend
extern "C" void initforParams(int, int, const InputDF &, OutputDF &, OutputDF &); // as initforParams
extern "C" void c_intinit(int, OutputDF &); // as intinit
extern "C" void loadBorder(const InputDF &, OutputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &, const InputDF &); // as loadBorder
extern "C" void loadData(int, int, OutputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &, OutputDF &); // as loadData
extern "C" void outputData(int, int, const InputDF &, const InputDF &); // as outputData
extern "C" void c_rinit(double, OutputDF &); // as rinit
extern "C" void setBorder_x(const InputDF &, const InputDF &, OutputDF &, OutputDF &); // as setBorder_x
extern "C" void setBorder_y(const InputDF &, const InputDF &, OutputDF &, OutputDF &); // as setBorder_y
extern "C" void setBorder_z(const InputDF &, const InputDF &, OutputDF &, OutputDF &); // as setBorder_z
extern "C" void c_vinit(OutputDF &); // as vinit

BlockRetStatus block_99(CF &self)
{
	// request a[1][it][(size_x)-(1)][y][z]
	self.request(self.id(3)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request cntstep[1][(size_x)-(1)][y][z]
	self.request(self.id(4)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request c[1][it][(size_x)-(1)][y][z]
	self.request(self.id(5)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request b[1][it][(size_x)-(1)][y][z]
	self.request(self.id(6)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request f[1][it][(size_x)-(1)][y][z]
	self.request(self.id(7)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z]
	self.request(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request params[(size_x)-(1)][y][z]
	self.request(self.id(9)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=100;
	return CONTINUE;
}

// Request : cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
BlockRetStatus block_100(CF &self)
{
	// wait a[1][it][(size_x)-(1)][y][z]
	if (self.wait(self.id(3)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[1][(size_x)-(1)][y][z]
	if (self.wait(self.id(4)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[1][it][(size_x)-(1)][y][z]
	if (self.wait(self.id(5)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait b[1][it][(size_x)-(1)][y][z]
	if (self.wait(self.id(6)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[1][it][(size_x)-(1)][y][z]
	if (self.wait(self.id(7)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z]
	if (self.wait(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[(size_x)-(1)][y][z]
	if (self.wait(self.id(9)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=101;
	return CONTINUE;
}

// After requests: cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
BlockRetStatus block_101(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
		calccoef_pr_x(
			// int ((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(2))).get_int())))*((self.wait(self.id(1))).get_int())))+(static_cast<int>((static_cast<int>((self.arg(0).get_int())+(1)))*((self.wait(self.id(0))).get_int())))))-(1)), 
			// int cntstep[1][(size_x)-(1)][y][z]
			self.wait(self.id(4)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).get_int(), 
			// int j
			self.arg(3).get_int(), 
			// value params[(size_x)-(1)][y][z]
			self.wait(self.id(9)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value a[1][it][(size_x)-(1)][y][z]
			self.wait(self.id(3)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value b[1][it][(size_x)-(1)][y][z]
			self.wait(self.id(6)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value c[1][it][(size_x)-(1)][y][z]
			self.wait(self.id(5)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value f[1][it][(size_x)-(1)][y][z]
			self.wait(self.id(7)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// name alfa[1][it][j][(size_x)-(1)][y][z]
			_out_0, 
			// name beta[1][it][j][(size_x)-(1)][y][z]
			_out_1, 
			// value alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z]
			self.wait(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// name alfa_beta_beg6[1][it][j][size_x][y][z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(10)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(11)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][(self.wait(self.id(0))).get_int()][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	self.destroy(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][(self.wait(self.id(0))).get_int()][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// req_unlimited: alfa[1][it][j][(size_x)-(1)][y][z]
	{		DF posted=self.wait(self.id(10)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(10)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[1][it][j][(size_x)-(1)][y][z]
	{		DF posted=self.wait(self.id(11)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(11)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[1][it][j][size_x][y][z]
	{		DF posted=self.wait(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][(self.wait(self.id(0))).get_int()][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][(self.wait(self.id(0))).get_int()][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_102(CF &self)
{
	// request_preliminary size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=103;
	return CONTINUE;
}

// RequestPreliminary : cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_103(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=104;
	return CONTINUE;
}

// After requests: cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_104(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));
	// request size_y
	self.request(self.id(1), CyclicLocator(0));
	// request size_z
	self.request(self.id(2), CyclicLocator(0));

	self.NextBlock=105;
	return CONTINUE;
}

// Request : cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_105(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=106;
	return CONTINUE;
}

// After requests: cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_106(CF &self)
{
	// request alfa[1][it][j][(size_x)-(1)][y][z]
	self.request(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request beta[1][it][j][(size_x)-(1)][y][z]
	self.request(self.id(4)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request ubeg[1][it][(size_x)-(1)][y][z]
	self.request(self.id(5)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request params[(size_x)-(1)][y][z]
	self.request(self.id(6)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request cntstep[1][(size_x)-(1)][y][z]
	self.request(self.id(7)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=107;
	return CONTINUE;
}

// Request : cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_107(CF &self)
{
	// wait alfa[1][it][j][(size_x)-(1)][y][z]
	if (self.wait(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait beta[1][it][j][(size_x)-(1)][y][z]
	if (self.wait(self.id(4)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait ubeg[1][it][(size_x)-(1)][y][z]
	if (self.wait(self.id(5)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[(size_x)-(1)][y][z]
	if (self.wait(self.id(6)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[1][(size_x)-(1)][y][z]
	if (self.wait(self.id(7)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=108;
	return CONTINUE;
}

// After requests: cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_108(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
		calcVal(
			// int ((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(1))).get_int())))*((self.wait(self.id(2))).get_int())))+(static_cast<int>((static_cast<int>((self.arg(0).get_int())+(1)))*((self.wait(self.id(0))).get_int())))))-(1)), 
			// int 1
			1, 
			// int cntstep[1][(size_x)-(1)][y][z]
			self.wait(self.id(7)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).get_int(), 
			// value params[(size_x)-(1)][y][z]
			self.wait(self.id(6)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value alfa[1][it][j][(size_x)-(1)][y][z]
			self.wait(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value beta[1][it][j][(size_x)-(1)][y][z]
			self.wait(self.id(4)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// name u_cur[1][it][j][(size_x)-(1)][y][z]
			_out_0, 
			// name ubeg6[1][it][j][(size_x)-(2)][y][z]
			_out_1, 
			// value ubeg[1][it][(size_x)-(1)][y][z]
			self.wait(self.id(5)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(9)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	self.destroy(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(4)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// req_unlimited: u_cur[1][it][j][(size_x)-(1)][y][z]
	{		DF posted=self.wait(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[1][it][j][(size_x)-(2)][y][z]
	{		DF posted=self.wait(self.id(9)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(9)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(2)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_109(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=110;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_110(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=111;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_111(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(112);
		child->arg(0)=_lc_x;
		child->arg(1)=self.arg(0).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(11);
		child->id(11)=self.id(12);
	}

	} // for
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_112(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=113;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_113(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=114;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_114(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(115);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(11);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_115(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=116;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_116(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=117;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_117(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l174: reduce_u(cntfor[1][x][y][z], x, y, z, u_cur[1][it], u[1][it][x][y][z]);
		CF *child=self.fork(118);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	{ // FORK_BI: cf fill_u_x[x][y][z]: fill_u(1, cntstep[1][x][y][z], params[x][y][z], u[1][it][x][y][z], u_c[2][it][x][y][z]);
		CF *child=self.fork(122);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(4);
		child->id(1)=self.id(5);
		child->id(2)=self.id(3);
		child->id(3)=self.id(6);
		child->id(4)=self.id(7);
		child->id(5)=self.id(8);
		child->id(6)=self.id(9);
		child->id(7)=self.id(10);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l174: reduce_u(cntfor[1][x][y][z], x, y, z, u_cur[1][it], u[1][it][x][y][z]);
BlockRetStatus block_118(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntfor[1][x][y][z]
	self.request(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=119;
	return CONTINUE;
}

// Request : cf _l174: reduce_u(cntfor[1][x][y][z], x, y, z, u_cur[1][it], u[1][it][x][y][z]);
BlockRetStatus block_119(CF &self)
{
	// wait cntfor[1][x][y][z]
	if (self.wait(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=120;
	return CONTINUE;
}

// After requests: cf _l174: reduce_u(cntfor[1][x][y][z], x, y, z, u_cur[1][it], u[1][it][x][y][z]);
BlockRetStatus block_120(CF &self)
{
	{ // EXEC_STRUCT: cf _l174: reduce_u(cntfor[1][x][y][z], x, y, z, u_cur[1][it], u[1][it][x][y][z]);
		CF *child=self.fork(121);
		child->arg(0)=self.wait(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int();
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1)[1][self.arg(3).get_int()];
		child->id(1)=self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()];
	}

	return EXIT;
}

// BI_EXEC: cf fill_u_x[x][y][z]: fill_u(1, cntstep[1][x][y][z], params[x][y][z], u[1][it][x][y][z], u_c[2][it][x][y][z]);
BlockRetStatus block_122(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request params[x][y][z]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request cntstep[1][x][y][z]
	self.request(self.id(1)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u[1][it][x][y][z]
	self.request(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=123;
	return CONTINUE;
}

// Request : cf fill_u_x[x][y][z]: fill_u(1, cntstep[1][x][y][z], params[x][y][z], u[1][it][x][y][z], u_c[2][it][x][y][z]);
BlockRetStatus block_123(CF &self)
{
	// wait params[x][y][z]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[1][x][y][z]
	if (self.wait(self.id(1)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u[1][it][x][y][z]
	if (self.wait(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=124;
	return CONTINUE;
}

// After requests: cf fill_u_x[x][y][z]: fill_u(1, cntstep[1][x][y][z], params[x][y][z], u[1][it][x][y][z], u_c[2][it][x][y][z]);
BlockRetStatus block_124(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf fill_u_x[x][y][z]: fill_u(1, cntstep[1][x][y][z], params[x][y][z], u[1][it][x][y][z], u_c[2][it][x][y][z]);
		fill_u(
			// int 1
			1, 
			// int cntstep[1][x][y][z]
			self.wait(self.id(1)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u[1][it][x][y][z]
			self.wait(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_c[2][it][x][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	self.destroy(self.id(4)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(6)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(7)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_c[2][it][x][y][z]
	{		DF posted=self.wait(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_125(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=126;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_126(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=127;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_127(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(128);
		child->arg(0)=_lc_x;
		child->arg(1)=self.arg(0).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(11);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_128(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=129;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_129(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=130;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_130(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf init_alfa_beta_y[x][0][z]: init_alfa_beta(cntstep[2][x][0][z], alfa_beta_beg[2][it][x][0][z]);
		CF *child=self.fork(131);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(134);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(3);
		child->id(1)=self.id(4);
		child->id(2)=self.id(5);
		child->id(3)=self.id(6);
		child->id(4)=self.id(7);
		child->id(5)=self.id(8);
		child->id(6)=self.id(9);
	}

	{ // FORK_BI: cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
		CF *child=self.fork(140);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(3);
		child->id(1)=self.id(1);
		child->id(2)=self.id(10);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf init_alfa_beta_y[x][0][z]: init_alfa_beta(cntstep[2][x][0][z], alfa_beta_beg[2][it][x][0][z]);
BlockRetStatus block_131(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[2][x][0][z]
	self.request(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=132;
	return CONTINUE;
}

// Request : cf init_alfa_beta_y[x][0][z]: init_alfa_beta(cntstep[2][x][0][z], alfa_beta_beg[2][it][x][0][z]);
BlockRetStatus block_132(CF &self)
{
	// wait cntstep[2][x][0][z]
	if (self.wait(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=133;
	return CONTINUE;
}

// After requests: cf init_alfa_beta_y[x][0][z]: init_alfa_beta(cntstep[2][x][0][z], alfa_beta_beg[2][it][x][0][z]);
BlockRetStatus block_133(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf init_alfa_beta_y[x][0][z]: init_alfa_beta(cntstep[2][x][0][z], alfa_beta_beg[2][it][x][0][z]);
		init_alfa_beta(
			// int cntstep[2][x][0][z]
			self.wait(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).get_int(), 
			// name alfa_beta_beg[2][it][x][0][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: alfa_beta_beg[2][it][x][0][z]
	{		DF posted=self.wait(self.id(1)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]);
	self.post(self.id(1)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_134(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=135;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_135(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=136;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_136(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: cf calcCoef_y[x][y][z]: calcCoef_y(params[x][y][z], u_c[1][it][x][y][z], u_c[2][it][x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z]);
		CF *child=self.fork(137);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calcCoef_y[x][y][z]: calcCoef_y(params[x][y][z], u_c[1][it][x][y][z], u_c[2][it][x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z]);
BlockRetStatus block_137(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request u_c[1][it][x][y][z]
	self.request(self.id(0)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u_c[2][it][x][y][z]
	self.request(self.id(0)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=138;
	return CONTINUE;
}

// Request : cf calcCoef_y[x][y][z]: calcCoef_y(params[x][y][z], u_c[1][it][x][y][z], u_c[2][it][x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z]);
BlockRetStatus block_138(CF &self)
{
	// wait u_c[1][it][x][y][z]
	if (self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_c[2][it][x][y][z]
	if (self.wait(self.id(0)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=139;
	return CONTINUE;
}

// After requests: cf calcCoef_y[x][y][z]: calcCoef_y(params[x][y][z], u_c[1][it][x][y][z], u_c[2][it][x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z]);
BlockRetStatus block_139(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		DF _out_3;
		// EXEC_EXTERN cf calcCoef_y[x][y][z]: calcCoef_y(params[x][y][z], u_c[1][it][x][y][z], u_c[2][it][x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z]);
		calcCoef_y(
			// value params[x][y][z]
			self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[1][it][x][y][z]
			self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[2][it][x][y][z]
			self.wait(self.id(0)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name a[2][it][x][y][z]
			_out_0, 
			// name b[2][it][x][y][z]
			_out_1, 
			// name c[2][it][x][y][z]
			_out_2, 
			// name f[2][it][x][y][z]
			_out_3);

		{
			DF stored=_out_0;
			self.store(self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(4)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_3;
			self.store(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: a[2][it][x][y][z]
	{		DF posted=self.wait(self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: b[2][it][x][y][z]
	{		DF posted=self.wait(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: c[2][it][x][y][z]
	{		DF posted=self.wait(self.id(4)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: f[2][it][x][y][z]
	{		DF posted=self.wait(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_140(CF &self)
{
	// request_preliminary size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=141;
	return CONTINUE;
}

// RequestPreliminary : cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_141(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=142;
	return CONTINUE;
}

// After requests: cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_142(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=143;
	return CONTINUE;
}

// Request : cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_143(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=144;
	return CONTINUE;
}

// After requests: cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_144(CF &self)
{
	// request cntstep[2][x][(size_y)-(1)][z]
	self.request(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=145;
	return CONTINUE;
}

// Request : cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_145(CF &self)
{
	// wait cntstep[2][x][(size_y)-(1)][z]
	if (self.wait(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=146;
	return CONTINUE;
}

// After requests: cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_146(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf init_uend_y[x][(size_y)-(1)][z]: init_uend(cntstep[2][x][(size_y)-(1)][z], ubeg[2][it][x][(size_y)-(1)][z]);
		init_uend(
			// int cntstep[2][x][(size_y)-(1)][z]
			self.wait(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).get_int(), 
			// name ubeg[2][it][x][(size_y)-(1)][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(2)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: ubeg[2][it][x][(size_y)-(1)][z]
	{		DF posted=self.wait(self.id(2)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]);
	self.post(self.id(2)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_147(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=148;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_148(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=149;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_149(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(150);
		child->arg(0)=_lc_x;
		child->arg(1)=self.arg(0).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(11);
		child->id(11)=self.id(12);
		child->id(12)=self.id(13);
		child->id(13)=self.id(14);
		child->id(14)=self.id(15);
		child->id(15)=self.id(0);
		child->id(16)=self.id(16);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_150(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=151;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_151(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=152;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_152(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: for k=0..(cntfor[2][x][0][z])-(1);
		CF *child=self.fork(153);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(11);
		child->id(11)=self.id(12);
		child->id(12)=self.id(0);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
	}

	{ // FORK_BI: for y=1..(size_y)-(2);
		CF *child=self.fork(165);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(12);
		child->id(1)=self.id(1);
		child->id(2)=self.id(2);
		child->id(3)=self.id(11);
		child->id(4)=self.id(4);
		child->id(5)=self.id(3);
		child->id(6)=self.id(7);
		child->id(7)=self.id(5);
		child->id(8)=self.id(6);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(0);
		child->id(12)=self.id(15);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
	}

	{ // FORK_BI: for k=0..(cntfor[2][x][(size_y)-(1)][z])-(1);
		CF *child=self.fork(177);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(12);
		child->id(1)=self.id(1);
		child->id(2)=self.id(3);
		child->id(3)=self.id(7);
		child->id(4)=self.id(11);
		child->id(5)=self.id(5);
		child->id(6)=self.id(6);
		child->id(7)=self.id(2);
		child->id(8)=self.id(4);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(15);
		child->id(12)=self.id(0);
		child->id(13)=self.id(16);
		child->id(14)=self.id(14);
		child->id(15)=self.id(13);
	}

	} // for
	return EXIT;
}

// BI_FOR: for k = 0 .. (cntfor[2][x][0][z])-(1)
BlockRetStatus block_153(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[2][x][0][z]
	self.request(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(0));

	self.NextBlock=154;
	return CONTINUE;
}

// Request : for k = 0 .. (cntfor[2][x][0][z])-(1)
BlockRetStatus block_154(CF &self)
{
	// wait cntfor[2][x][0][z]
	if (self.wait(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=155;
	return CONTINUE;
}

// After requests: for k = 0 .. (cntfor[2][x][0][z])-(1)
BlockRetStatus block_155(CF &self)
{
	for (int _lc_k=0; _lc_k<=static_cast<int>((self.wait(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).get_int())-(1)); _lc_k++) {

// GEN BODY: for k = 0 .. (cntfor[2][x][0][z])-(1)
	{ // FORK_BI: cf calccoef_pr_y[k][x][0][z]: calccoef_pr_y(cntstep[2][x][0][z], k, params[x][0][z], a[2][it][x][0][z], b[2][it][x][0][z], c[2][it][x][0][z], f[2][it][x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], alfa_beta_beg[2][it][x][0][z], alfa_beta_beg6[2][it][k][x][1][z]);
		CF *child=self.fork(156);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_k;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
	}

	{ // FORK_BI: if (size_y)>(1)
		CF *child=self.fork(159);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_k;
		child->id(0)=self.id(11);
		child->id(1)=self.id(2);
		child->id(2)=self.id(9);
		child->id(3)=self.id(12);
		child->id(4)=self.id(6);
		child->id(5)=self.id(8);
		child->id(6)=self.id(13);
		child->id(7)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_y[k][x][0][z]: calccoef_pr_y(cntstep[2][x][0][z], k, params[x][0][z], a[2][it][x][0][z], b[2][it][x][0][z], c[2][it][x][0][z], f[2][it][x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], alfa_beta_beg[2][it][x][0][z], alfa_beta_beg6[2][it][k][x][1][z]);
BlockRetStatus block_156(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request b[2][it][x][0][z]
	self.request(self.id(0)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request cntstep[2][x][0][z]
	self.request(self.id(1)[2][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request f[2][it][x][0][z]
	self.request(self.id(2)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request a[2][it][x][0][z]
	self.request(self.id(3)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request c[2][it][x][0][z]
	self.request(self.id(4)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request params[x][0][z]
	self.request(self.id(5)[self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request alfa_beta_beg[2][it][x][0][z]
	self.request(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=157;
	return CONTINUE;
}

// Request : cf calccoef_pr_y[k][x][0][z]: calccoef_pr_y(cntstep[2][x][0][z], k, params[x][0][z], a[2][it][x][0][z], b[2][it][x][0][z], c[2][it][x][0][z], f[2][it][x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], alfa_beta_beg[2][it][x][0][z], alfa_beta_beg6[2][it][k][x][1][z]);
BlockRetStatus block_157(CF &self)
{
	// wait b[2][it][x][0][z]
	if (self.wait(self.id(0)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[2][x][0][z]
	if (self.wait(self.id(1)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[2][it][x][0][z]
	if (self.wait(self.id(2)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait a[2][it][x][0][z]
	if (self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[2][it][x][0][z]
	if (self.wait(self.id(4)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][0][z]
	if (self.wait(self.id(5)[self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa_beta_beg[2][it][x][0][z]
	if (self.wait(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=158;
	return CONTINUE;
}

// After requests: cf calccoef_pr_y[k][x][0][z]: calccoef_pr_y(cntstep[2][x][0][z], k, params[x][0][z], a[2][it][x][0][z], b[2][it][x][0][z], c[2][it][x][0][z], f[2][it][x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], alfa_beta_beg[2][it][x][0][z], alfa_beta_beg6[2][it][k][x][1][z]);
BlockRetStatus block_158(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_y[k][x][0][z]: calccoef_pr_y(cntstep[2][x][0][z], k, params[x][0][z], a[2][it][x][0][z], b[2][it][x][0][z], c[2][it][x][0][z], f[2][it][x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], alfa_beta_beg[2][it][x][0][z], alfa_beta_beg6[2][it][k][x][1][z]);
		calccoef_pr_y(
			// int cntstep[2][x][0][z]
			self.wait(self.id(1)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).get_int(), 
			// int k
			self.arg(3).get_int(), 
			// value params[x][0][z]
			self.wait(self.id(5)[self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// value a[2][it][x][0][z]
			self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// value b[2][it][x][0][z]
			self.wait(self.id(0)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// value c[2][it][x][0][z]
			self.wait(self.id(4)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// value f[2][it][x][0][z]
			self.wait(self.id(2)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// name alfa[2][it][k][x][0][z]
			_out_0, 
			// name beta[2][it][k][x][0][z]
			_out_1, 
			// value alfa_beta_beg[2][it][x][0][z]
			self.wait(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// name alfa_beta_beg6[2][it][k][x][1][z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(7)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][1][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: alfa[2][it][k][x][0][z]
	{		DF posted=self.wait(self.id(7)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]);
	self.post(self.id(7)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[2][it][k][x][0][z]
	{		DF posted=self.wait(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]);
	self.post(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[2][it][k][x][1][z]
	{		DF posted=self.wait(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][1][self.arg(1).get_int()]);
	self.post(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][1][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((1)*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// IF: preparations: if (size_y)>(1)
BlockRetStatus block_159(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=160;
	return CONTINUE;
}

// Request : if (size_y)>(1)
BlockRetStatus block_160(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=161;
	return CONTINUE;
}

// After requests: if (size_y)>(1)
BlockRetStatus block_161(CF &self)
{
	if (0!=static_cast<int>(((self.wait(self.id(0))).get_int())>(1))) {

// GEN BODY: if (size_y)>(1)
	{ // FORK_BI: cf calcVal_y[k][x][0][z]: calcVal((((z)*(size_y))*(size_z))+(x), 2, cntstep[2][x][0][z], params[x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], u_cur[2][it][k][x][0][z], ubeg6[2][it][k][x][(0)-(1)][z], ubeg6[2][it][k][x][0][z]);
		CF *child=self.fork(162);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(0);
		child->id(7)=self.id(7);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf calcVal_y[k][x][0][z]: calcVal((((z)*(size_y))*(size_z))+(x), 2, cntstep[2][x][0][z], params[x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], u_cur[2][it][k][x][0][z], ubeg6[2][it][k][x][(0)-(1)][z], ubeg6[2][it][k][x][0][z]);
BlockRetStatus block_162(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[2][x][0][z]
	self.request(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request beta[2][it][k][x][0][z]
	self.request(self.id(1)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_z
	self.request(self.id(2), CyclicLocator(0));
	// request params[x][0][z]
	self.request(self.id(3)[self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request alfa[2][it][k][x][0][z]
	self.request(self.id(4)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request ubeg6[2][it][k][x][0][z]
	self.request(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_y
	self.request(self.id(6), CyclicLocator(0));

	self.NextBlock=163;
	return CONTINUE;
}

// Request : cf calcVal_y[k][x][0][z]: calcVal((((z)*(size_y))*(size_z))+(x), 2, cntstep[2][x][0][z], params[x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], u_cur[2][it][k][x][0][z], ubeg6[2][it][k][x][(0)-(1)][z], ubeg6[2][it][k][x][0][z]);
BlockRetStatus block_163(CF &self)
{
	// wait cntstep[2][x][0][z]
	if (self.wait(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait beta[2][it][k][x][0][z]
	if (self.wait(self.id(1)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}

	// wait params[x][0][z]
	if (self.wait(self.id(3)[self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa[2][it][k][x][0][z]
	if (self.wait(self.id(4)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait ubeg6[2][it][k][x][0][z]
	if (self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(6)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=164;
	return CONTINUE;
}

// After requests: cf calcVal_y[k][x][0][z]: calcVal((((z)*(size_y))*(size_z))+(x), 2, cntstep[2][x][0][z], params[x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], u_cur[2][it][k][x][0][z], ubeg6[2][it][k][x][(0)-(1)][z], ubeg6[2][it][k][x][0][z]);
BlockRetStatus block_164(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_y[k][x][0][z]: calcVal((((z)*(size_y))*(size_z))+(x), 2, cntstep[2][x][0][z], params[x][0][z], alfa[2][it][k][x][0][z], beta[2][it][k][x][0][z], u_cur[2][it][k][x][0][z], ubeg6[2][it][k][x][(0)-(1)][z], ubeg6[2][it][k][x][0][z]);
		calcVal(
			// int (((z)*(size_y))*(size_z))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(6))).get_int())))*((self.wait(self.id(2))).get_int())))+(self.arg(0).get_int())), 
			// int 2
			2, 
			// int cntstep[2][x][0][z]
			self.wait(self.id(0)[2][self.arg(0).get_int()][0][self.arg(1).get_int()]).get_int(), 
			// value params[x][0][z]
			self.wait(self.id(3)[self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// value alfa[2][it][k][x][0][z]
			self.wait(self.id(4)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// value beta[2][it][k][x][0][z]
			self.wait(self.id(1)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]), 
			// name u_cur[2][it][k][x][0][z]
			_out_0, 
			// name ubeg6[2][it][k][x][(0)-(1)][z]
			_out_1, 
			// value ubeg6[2][it][k][x][0][z]
			self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(7)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>((0)-(1))][self.arg(1).get_int()], stored);
		}
	}

	self.destroy(self.id(4)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(1)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>((0)-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>((0)-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// req_unlimited: u_cur[2][it][k][x][0][z]
	{		DF posted=self.wait(self.id(7)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()]);
	self.post(self.id(7)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][0][self.arg(1).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[2][it][k][x][(0)-(1)][z]
	{		DF posted=self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>((0)-(1))][self.arg(1).get_int()]);
	self.post(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>((0)-(1))][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>((0)-(1)))*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for y = 1 .. (size_y)-(2)
BlockRetStatus block_165(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=166;
	return CONTINUE;
}

// Request : for y = 1 .. (size_y)-(2)
BlockRetStatus block_166(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=167;
	return CONTINUE;
}

// After requests: for y = 1 .. (size_y)-(2)
BlockRetStatus block_167(CF &self)
{
	for (int _lc_y=1; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(2)); _lc_y++) {

// GEN BODY: for y = 1 .. (size_y)-(2)
	{ // FORK_BI: for k=0..(cntfor[2][x][y][z])-(1);
		CF *child=self.fork(168);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(0);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_FOR: for k = 0 .. (cntfor[2][x][y][z])-(1)
BlockRetStatus block_168(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[2][x][y][z]
	self.request(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=169;
	return CONTINUE;
}

// Request : for k = 0 .. (cntfor[2][x][y][z])-(1)
BlockRetStatus block_169(CF &self)
{
	// wait cntfor[2][x][y][z]
	if (self.wait(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=170;
	return CONTINUE;
}

// After requests: for k = 0 .. (cntfor[2][x][y][z])-(1)
BlockRetStatus block_170(CF &self)
{
	for (int _lc_k=0; _lc_k<=static_cast<int>((self.wait(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int())-(1)); _lc_k++) {

// GEN BODY: for k = 0 .. (cntfor[2][x][y][z])-(1)
	{ // FORK_BI: cf calccoef_pr_y[k][x][y][z]: calccoef_pr_y(cntstep[2][x][y][z], k, params[x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][(y)+(1)][z]);
		CF *child=self.fork(171);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->arg(4)=_lc_k;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
	}

	{ // FORK_BI: cf calcVal_y[k][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 2, cntstep[2][x][y][z], params[x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], u_cur[2][it][k][x][y][z], ubeg6[2][it][k][x][(y)-(1)][z], ubeg6[2][it][k][x][y][z]);
		CF *child=self.fork(174);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->arg(4)=_lc_k;
		child->id(0)=self.id(5);
		child->id(1)=self.id(8);
		child->id(2)=self.id(10);
		child->id(3)=self.id(11);
		child->id(4)=self.id(12);
		child->id(5)=self.id(13);
		child->id(6)=self.id(9);
		child->id(7)=self.id(4);
		child->id(8)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_y[k][x][y][z]: calccoef_pr_y(cntstep[2][x][y][z], k, params[x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][(y)+(1)][z]);
BlockRetStatus block_171(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request b[2][it][x][y][z]
	self.request(self.id(0)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request alfa_beta_beg6[2][it][k][x][y][z]
	self.request(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request f[2][it][x][y][z]
	self.request(self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request cntstep[2][x][y][z]
	self.request(self.id(3)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request a[2][it][x][y][z]
	self.request(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request c[2][it][x][y][z]
	self.request(self.id(6)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=172;
	return CONTINUE;
}

// Request : cf calccoef_pr_y[k][x][y][z]: calccoef_pr_y(cntstep[2][x][y][z], k, params[x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][(y)+(1)][z]);
BlockRetStatus block_172(CF &self)
{
	// wait b[2][it][x][y][z]
	if (self.wait(self.id(0)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa_beta_beg6[2][it][k][x][y][z]
	if (self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[2][it][x][y][z]
	if (self.wait(self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[2][x][y][z]
	if (self.wait(self.id(3)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait a[2][it][x][y][z]
	if (self.wait(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[2][it][x][y][z]
	if (self.wait(self.id(6)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=173;
	return CONTINUE;
}

// After requests: cf calccoef_pr_y[k][x][y][z]: calccoef_pr_y(cntstep[2][x][y][z], k, params[x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][(y)+(1)][z]);
BlockRetStatus block_173(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_y[k][x][y][z]: calccoef_pr_y(cntstep[2][x][y][z], k, params[x][y][z], a[2][it][x][y][z], b[2][it][x][y][z], c[2][it][x][y][z], f[2][it][x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][y][z], alfa_beta_beg6[2][it][k][x][(y)+(1)][z]);
		calccoef_pr_y(
			// int cntstep[2][x][y][z]
			self.wait(self.id(3)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// int k
			self.arg(4).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value a[2][it][x][y][z]
			self.wait(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value b[2][it][x][y][z]
			self.wait(self.id(0)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value c[2][it][x][y][z]
			self.wait(self.id(6)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value f[2][it][x][y][z]
			self.wait(self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name alfa[2][it][k][x][y][z]
			_out_0, 
			// name beta[2][it][k][x][y][z]
			_out_1, 
			// value alfa_beta_beg6[2][it][k][x][y][z]
			self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name alfa_beta_beg6[2][it][k][x][(y)+(1)][z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(7)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(8)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())+(1))][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: alfa[2][it][k][x][y][z]
	{		DF posted=self.wait(self.id(7)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(7)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[2][it][k][x][y][z]
	{		DF posted=self.wait(self.id(8)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(8)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[2][it][k][x][(y)+(1)][z]
	{		DF posted=self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())+(1))][self.arg(2).get_int()]);
	self.post(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())+(1))][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>((self.arg(1).get_int())+(1)))*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf calcVal_y[k][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 2, cntstep[2][x][y][z], params[x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], u_cur[2][it][k][x][y][z], ubeg6[2][it][k][x][(y)-(1)][z], ubeg6[2][it][k][x][y][z]);
BlockRetStatus block_174(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request params[x][y][z]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request alfa[2][it][k][x][y][z]
	self.request(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_y
	self.request(self.id(2), CyclicLocator(0));
	// request size_z
	self.request(self.id(3), CyclicLocator(0));
	// request size_x
	self.request(self.id(4), CyclicLocator(0));
	// request ubeg6[2][it][k][x][y][z]
	self.request(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request beta[2][it][k][x][y][z]
	self.request(self.id(6)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request cntstep[2][x][y][z]
	self.request(self.id(7)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=175;
	return CONTINUE;
}

// Request : cf calcVal_y[k][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 2, cntstep[2][x][y][z], params[x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], u_cur[2][it][k][x][y][z], ubeg6[2][it][k][x][(y)-(1)][z], ubeg6[2][it][k][x][y][z]);
BlockRetStatus block_175(CF &self)
{
	// wait params[x][y][z]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa[2][it][k][x][y][z]
	if (self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(3)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(4)).is_unset()) {
		return WAIT;
	}

	// wait ubeg6[2][it][k][x][y][z]
	if (self.wait(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait beta[2][it][k][x][y][z]
	if (self.wait(self.id(6)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[2][x][y][z]
	if (self.wait(self.id(7)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=176;
	return CONTINUE;
}

// After requests: cf calcVal_y[k][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 2, cntstep[2][x][y][z], params[x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], u_cur[2][it][k][x][y][z], ubeg6[2][it][k][x][(y)-(1)][z], ubeg6[2][it][k][x][y][z]);
BlockRetStatus block_176(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_y[k][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 2, cntstep[2][x][y][z], params[x][y][z], alfa[2][it][k][x][y][z], beta[2][it][k][x][y][z], u_cur[2][it][k][x][y][z], ubeg6[2][it][k][x][(y)-(1)][z], ubeg6[2][it][k][x][y][z]);
		calcVal(
			// int ((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(2))).get_int())))*((self.wait(self.id(3))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(4))).get_int())))))+(self.arg(0).get_int())), 
			// int 2
			2, 
			// int cntstep[2][x][y][z]
			self.wait(self.id(7)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value alfa[2][it][k][x][y][z]
			self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value beta[2][it][k][x][y][z]
			self.wait(self.id(6)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_cur[2][it][k][x][y][z]
			_out_0, 
			// name ubeg6[2][it][k][x][(y)-(1)][z]
			_out_1, 
			// value ubeg6[2][it][k][x][y][z]
			self.wait(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())-(1))][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(1)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(6)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_cur[2][it][k][x][y][z]
	{		DF posted=self.wait(self.id(8)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(8)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[2][it][k][x][(y)-(1)][z]
	{		DF posted=self.wait(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())-(1))][self.arg(2).get_int()]);
	self.post(self.id(5)[2][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())-(1))][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>((self.arg(1).get_int())-(1)))*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for k = 0 .. (cntfor[2][x][(size_y)-(1)][z])-(1)
BlockRetStatus block_177(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=178;
	return CONTINUE;
}

// Request : for k = 0 .. (cntfor[2][x][(size_y)-(1)][z])-(1)
BlockRetStatus block_178(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=179;
	return CONTINUE;
}

// After requests: for k = 0 .. (cntfor[2][x][(size_y)-(1)][z])-(1)
BlockRetStatus block_179(CF &self)
{
	// request cntfor[2][x][(size_y)-(1)][z]
	self.request(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(0));

	self.NextBlock=180;
	return CONTINUE;
}

// Request : for k = 0 .. (cntfor[2][x][(size_y)-(1)][z])-(1)
BlockRetStatus block_180(CF &self)
{
	// wait cntfor[2][x][(size_y)-(1)][z]
	if (self.wait(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=181;
	return CONTINUE;
}

// After requests: for k = 0 .. (cntfor[2][x][(size_y)-(1)][z])-(1)
BlockRetStatus block_181(CF &self)
{
	for (int _lc_k=0; _lc_k<=static_cast<int>((self.wait(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).get_int())-(1)); _lc_k++) {

// GEN BODY: for k = 0 .. (cntfor[2][x][(size_y)-(1)][z])-(1)
	{ // FORK_BI: if (size_y)>(1)
		CF *child=self.fork(182);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_k;
		child->id(0)=self.id(0);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
	}

	{ // FORK_BI: cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
		CF *child=self.fork(192);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_k;
		child->id(0)=self.id(0);
		child->id(1)=self.id(11);
		child->id(2)=self.id(12);
		child->id(3)=self.id(9);
		child->id(4)=self.id(3);
		child->id(5)=self.id(10);
		child->id(6)=self.id(13);
		child->id(7)=self.id(2);
		child->id(8)=self.id(14);
		child->id(9)=self.id(15);
	}

	} // for
	return EXIT;
}

// IF: preparations: if (size_y)>(1)
BlockRetStatus block_182(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=183;
	return CONTINUE;
}

// Request : if (size_y)>(1)
BlockRetStatus block_183(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=184;
	return CONTINUE;
}

// After requests: if (size_y)>(1)
BlockRetStatus block_184(CF &self)
{
	if (0!=static_cast<int>(((self.wait(self.id(0))).get_int())>(1))) {

// GEN BODY: if (size_y)>(1)
	{ // FORK_BI: cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
		CF *child=self.fork(185);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
		child->id(2)=self.id(2);
		child->id(3)=self.id(3);
		child->id(4)=self.id(4);
		child->id(5)=self.id(5);
		child->id(6)=self.id(6);
		child->id(7)=self.id(7);
		child->id(8)=self.id(8);
		child->id(9)=self.id(9);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_185(CF &self)
{
	// request_preliminary size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=186;
	return CONTINUE;
}

// RequestPreliminary : cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_186(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=187;
	return CONTINUE;
}

// After requests: cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_187(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=188;
	return CONTINUE;
}

// Request : cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_188(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=189;
	return CONTINUE;
}

// After requests: cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_189(CF &self)
{
	// request cntstep[2][x][(size_y)-(1)][z]
	self.request(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request params[x][(size_y)-(1)][z]
	self.request(self.id(2)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z]
	self.request(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request a[2][it][x][(size_y)-(1)][z]
	self.request(self.id(4)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request c[2][it][x][(size_y)-(1)][z]
	self.request(self.id(5)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request b[2][it][x][(size_y)-(1)][z]
	self.request(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request f[2][it][x][(size_y)-(1)][z]
	self.request(self.id(7)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=190;
	return CONTINUE;
}

// Request : cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_190(CF &self)
{
	// wait cntstep[2][x][(size_y)-(1)][z]
	if (self.wait(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][(size_y)-(1)][z]
	if (self.wait(self.id(2)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z]
	if (self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait a[2][it][x][(size_y)-(1)][z]
	if (self.wait(self.id(4)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[2][it][x][(size_y)-(1)][z]
	if (self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait b[2][it][x][(size_y)-(1)][z]
	if (self.wait(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[2][it][x][(size_y)-(1)][z]
	if (self.wait(self.id(7)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=191;
	return CONTINUE;
}

// After requests: cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
BlockRetStatus block_191(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_y[k][x][(size_y)-(1)][z]: calccoef_pr_y(cntstep[2][x][(size_y)-(1)][z], k, params[x][(size_y)-(1)][z], a[2][it][x][(size_y)-(1)][z], b[2][it][x][(size_y)-(1)][z], c[2][it][x][(size_y)-(1)][z], f[2][it][x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z], alfa_beta_beg6[2][it][k][x][size_y][z]);
		calccoef_pr_y(
			// int cntstep[2][x][(size_y)-(1)][z]
			self.wait(self.id(1)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).get_int(), 
			// int k
			self.arg(3).get_int(), 
			// value params[x][(size_y)-(1)][z]
			self.wait(self.id(2)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// value a[2][it][x][(size_y)-(1)][z]
			self.wait(self.id(4)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// value b[2][it][x][(size_y)-(1)][z]
			self.wait(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// value c[2][it][x][(size_y)-(1)][z]
			self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// value f[2][it][x][(size_y)-(1)][z]
			self.wait(self.id(7)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// name alfa[2][it][k][x][(size_y)-(1)][z]
			_out_0, 
			// name beta[2][it][k][x][(size_y)-(1)][z]
			_out_1, 
			// value alfa_beta_beg6[2][it][k][x][(size_y)-(1)][z]
			self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// name alfa_beta_beg6[2][it][k][x][size_y][z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][(self.wait(self.id(0))).get_int()][self.arg(1).get_int()], stored);
		}
	}

	self.destroy(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][(self.wait(self.id(0))).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>(((self.wait(self.id(0))).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// req_unlimited: alfa[2][it][k][x][(size_y)-(1)][z]
	{		DF posted=self.wait(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]);
	self.post(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[2][it][k][x][(size_y)-(1)][z]
	{		DF posted=self.wait(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]);
	self.post(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[2][it][k][x][size_y][z]
	{		DF posted=self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][(self.wait(self.id(0))).get_int()][self.arg(1).get_int()]);
	self.post(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][(self.wait(self.id(0))).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>(((self.wait(self.id(0))).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_192(CF &self)
{
	// request_preliminary size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=193;
	return CONTINUE;
}

// RequestPreliminary : cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_193(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=194;
	return CONTINUE;
}

// After requests: cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_194(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));
	// request size_x
	self.request(self.id(1), CyclicLocator(0));
	// request size_z
	self.request(self.id(2), CyclicLocator(0));

	self.NextBlock=195;
	return CONTINUE;
}

// Request : cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_195(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=196;
	return CONTINUE;
}

// After requests: cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_196(CF &self)
{
	// request alfa[2][it][k][x][(size_y)-(1)][z]
	self.request(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request params[x][(size_y)-(1)][z]
	self.request(self.id(4)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request beta[2][it][k][x][(size_y)-(1)][z]
	self.request(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request ubeg[2][it][x][(size_y)-(1)][z]
	self.request(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// request cntstep[2][x][(size_y)-(1)][z]
	self.request(self.id(7)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=197;
	return CONTINUE;
}

// Request : cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_197(CF &self)
{
	// wait alfa[2][it][k][x][(size_y)-(1)][z]
	if (self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][(size_y)-(1)][z]
	if (self.wait(self.id(4)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait beta[2][it][k][x][(size_y)-(1)][z]
	if (self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait ubeg[2][it][x][(size_y)-(1)][z]
	if (self.wait(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[2][x][(size_y)-(1)][z]
	if (self.wait(self.id(7)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=198;
	return CONTINUE;
}

// After requests: cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
BlockRetStatus block_198(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_y[k][x][(size_y)-(1)][z]: calcVal(((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x), 2, cntstep[2][x][(size_y)-(1)][z], params[x][(size_y)-(1)][z], alfa[2][it][k][x][(size_y)-(1)][z], beta[2][it][k][x][(size_y)-(1)][z], u_cur[2][it][k][x][(size_y)-(1)][z], ubeg6[2][it][k][x][(size_y)-(2)][z], ubeg[2][it][x][(size_y)-(1)][z]);
		calcVal(
			// int ((((z)*(size_y))*(size_z))+(((size_y)-(1))*(size_x)))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(0))).get_int())))*((self.wait(self.id(2))).get_int())))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*((self.wait(self.id(1))).get_int())))))+(self.arg(0).get_int())), 
			// int 2
			2, 
			// int cntstep[2][x][(size_y)-(1)][z]
			self.wait(self.id(7)[2][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]).get_int(), 
			// value params[x][(size_y)-(1)][z]
			self.wait(self.id(4)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// value alfa[2][it][k][x][(size_y)-(1)][z]
			self.wait(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// value beta[2][it][k][x][(size_y)-(1)][z]
			self.wait(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]), 
			// name u_cur[2][it][k][x][(size_y)-(1)][z]
			_out_0, 
			// name ubeg6[2][it][k][x][(size_y)-(2)][z]
			_out_1, 
			// value ubeg[2][it][x][(size_y)-(1)][z]
			self.wait(self.id(6)[2][self.arg(2).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))][self.arg(1).get_int()], stored);
		}
	}

	self.destroy(self.id(3)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(5)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))));
	// req_unlimited: u_cur[2][it][k][x][(size_y)-(1)][z]
	{		DF posted=self.wait(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]);
	self.post(self.id(8)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[2][it][k][x][(size_y)-(2)][z]
	{		DF posted=self.wait(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))][self.arg(1).get_int()]);
	self.post(self.id(9)[2][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(2)))*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_199(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=200;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)