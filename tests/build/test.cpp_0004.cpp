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

BlockRetStatus block_399(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	for (int _lc_i=0; _lc_i<=static_cast<int>((static_cast<int>((self.arg(3).get_int())/(2)))-(1)); _lc_i++) {

// GEN BODY: for i = 0 .. ((cnt)/(2))-(1)
	{ // FORK_BI: cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
		CF *child=self.fork(400);
		child->arg(0)=_lc_i;
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
BlockRetStatus block_400(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request u_cur[(i)*(2)][x][y][z]
	self.request(self.id(0)[static_cast<int>((self.arg(0).get_int())*(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));
	// request u_cur[((i)*(2))+(1)][x][y][z]
	self.request(self.id(0)[static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))+(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));

	self.NextBlock=401;
	return CONTINUE;
}

// Request : cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
BlockRetStatus block_401(CF &self)
{
	// wait u_cur[(i)*(2)][x][y][z]
	if (self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())*(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_cur[((i)*(2))+(1)][x][y][z]
	if (self.wait(self.id(0)[static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))+(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=402;
	return CONTINUE;
}

// After requests: cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
BlockRetStatus block_402(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
		gather_arr(
			// value u_cur[(i)*(2)][x][y][z]
			self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())*(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]), 
			// value u_cur[((i)*(2))+(1)][x][y][z]
			self.wait(self.id(0)[static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))+(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]), 
			// name sums[i][x][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], stored);
		}
	}

	self.destroy(self.id(0)[static_cast<int>((self.arg(0).get_int())*(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));
	self.destroy(self.id(0)[static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))+(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));
	// req_unlimited: sums[i][x][y][z]
	{		DF posted=self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]);
	self.post(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf copy_g[(cnt)/(2)][x][y][z]: copy_v(u_cur[(cnt)-(1)][x][y][z], sums[(cnt)/(2)][x][y][z]);
BlockRetStatus block_403(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request u_cur[(cnt)-(1)][x][y][z]
	self.request(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));

	self.NextBlock=404;
	return CONTINUE;
}

// Request : cf copy_g[(cnt)/(2)][x][y][z]: copy_v(u_cur[(cnt)-(1)][x][y][z], sums[(cnt)/(2)][x][y][z]);
BlockRetStatus block_404(CF &self)
{
	// wait u_cur[(cnt)-(1)][x][y][z]
	if (self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=405;
	return CONTINUE;
}

// After requests: cf copy_g[(cnt)/(2)][x][y][z]: copy_v(u_cur[(cnt)-(1)][x][y][z], sums[(cnt)/(2)][x][y][z]);
BlockRetStatus block_405(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf copy_g[(cnt)/(2)][x][y][z]: copy_v(u_cur[(cnt)-(1)][x][y][z], sums[(cnt)/(2)][x][y][z]);
		copy_vector(
			// value u_cur[(cnt)-(1)][x][y][z]
			self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]), 
			// name sums[(cnt)/(2)][x][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[static_cast<int>((self.arg(0).get_int())/(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], stored);
		}
	}

	self.destroy(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));
	// req_unlimited: sums[(cnt)/(2)][x][y][z]
	{		DF posted=self.wait(self.id(1)[static_cast<int>((self.arg(0).get_int())/(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]);
	self.post(self.id(1)[static_cast<int>((self.arg(0).get_int())/(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l62: reduce_u(((cnt)/(2))+(1), x, y, z, sums, u_c);
BlockRetStatus block_406(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	{ // EXEC_STRUCT: cf _l62: reduce_u(((cnt)/(2))+(1), x, y, z, sums, u_c);
		CF *child=self.fork(121);
		child->arg(0)=static_cast<int>((static_cast<int>((self.arg(0).get_int())/(2)))+(1));
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	return EXIT;
}

