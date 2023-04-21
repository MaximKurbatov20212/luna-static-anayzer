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

BlockRetStatus block_300(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[3][x][y][z]
	self.request(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u[3][it][x][y][z]
	self.request(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=301;
	return CONTINUE;
}

// Request : cf fill_u_z[x][y][z]: fill_u(3, cntstep[3][x][y][z], params[x][y][z], u[3][it][x][y][z], u_c[4][it][x][y][z]);
BlockRetStatus block_301(CF &self)
{
	// wait cntstep[3][x][y][z]
	if (self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u[3][it][x][y][z]
	if (self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=302;
	return CONTINUE;
}

// After requests: cf fill_u_z[x][y][z]: fill_u(3, cntstep[3][x][y][z], params[x][y][z], u[3][it][x][y][z], u_c[4][it][x][y][z]);
BlockRetStatus block_302(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf fill_u_z[x][y][z]: fill_u(3, cntstep[3][x][y][z], params[x][y][z], u[3][it][x][y][z], u_c[4][it][x][y][z]);
		fill_u(
			// int 3
			3, 
			// int cntstep[3][x][y][z]
			self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u[3][it][x][y][z]
			self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_c[4][it][x][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	self.destroy(self.id(4)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(6)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(7)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_c[4][it][x][y][z]
	{		DF posted=self.wait(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_303(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=304;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_304(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=305;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_305(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(306);
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
	}

	} // for
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_306(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=307;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_307(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=308;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_308(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(309);
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
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_309(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=310;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_310(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=311;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_311(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf setBorder_x[x][y][z]: setBorder_x(params[x][y][z], u_c[4][it][x][y][z], sendar_x_L[(x)-(1)][y][z], sendar_x_R[(x)+(1)][y][z]);
		CF *child=self.fork(312);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
	}

	{ // FORK_BI: cf setBorder_y[x][y][z]: setBorder_y(params[x][y][z], u_c[4][it][x][y][z], sendar_y_T[x][(y)+(1)][z], sendar_y_B[x][(y)-(1)][z]);
		CF *child=self.fork(315);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(2);
		child->id(1)=self.id(1);
		child->id(2)=self.id(5);
		child->id(3)=self.id(6);
	}

	{ // FORK_BI: cf setBorder_z[x][y][z]: setBorder_z(params[x][y][z], u_c[4][it][x][y][z], sendar_z_F[x][y][(z)+(1)], sendar_z_B[x][y][(z)-(1)]);
		CF *child=self.fork(318);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(2);
		child->id(1)=self.id(1);
		child->id(2)=self.id(7);
		child->id(3)=self.id(8);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf setBorder_x[x][y][z]: setBorder_x(params[x][y][z], u_c[4][it][x][y][z], sendar_x_L[(x)-(1)][y][z], sendar_x_R[(x)+(1)][y][z]);
BlockRetStatus block_312(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request u_c[4][it][x][y][z]
	self.request(self.id(0)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=313;
	return CONTINUE;
}

// Request : cf setBorder_x[x][y][z]: setBorder_x(params[x][y][z], u_c[4][it][x][y][z], sendar_x_L[(x)-(1)][y][z], sendar_x_R[(x)+(1)][y][z]);
BlockRetStatus block_313(CF &self)
{
	// wait u_c[4][it][x][y][z]
	if (self.wait(self.id(0)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=314;
	return CONTINUE;
}

// After requests: cf setBorder_x[x][y][z]: setBorder_x(params[x][y][z], u_c[4][it][x][y][z], sendar_x_L[(x)-(1)][y][z], sendar_x_R[(x)+(1)][y][z]);
BlockRetStatus block_314(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf setBorder_x[x][y][z]: setBorder_x(params[x][y][z], u_c[4][it][x][y][z], sendar_x_L[(x)-(1)][y][z], sendar_x_R[(x)+(1)][y][z]);
		setBorder_x(
			// value params[x][y][z]
			self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[4][it][x][y][z]
			self.wait(self.id(0)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name sendar_x_L[(x)-(1)][y][z]
			_out_0, 
			// name sendar_x_R[(x)+(1)][y][z]
			_out_1);

		{
			DF stored=_out_0;
			self.store(self.id(2)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(3)[static_cast<int>((self.arg(0).get_int())+(1))][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: sendar_x_L[(x)-(1)][y][z]
	{		DF posted=self.wait(self.id(2)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(2)[static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: sendar_x_R[(x)+(1)][y][z]
	{		DF posted=self.wait(self.id(3)[static_cast<int>((self.arg(0).get_int())+(1))][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[static_cast<int>((self.arg(0).get_int())+(1))][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())+(1)))*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf setBorder_y[x][y][z]: setBorder_y(params[x][y][z], u_c[4][it][x][y][z], sendar_y_T[x][(y)+(1)][z], sendar_y_B[x][(y)-(1)][z]);
BlockRetStatus block_315(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request params[x][y][z]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u_c[4][it][x][y][z]
	self.request(self.id(1)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=316;
	return CONTINUE;
}

// Request : cf setBorder_y[x][y][z]: setBorder_y(params[x][y][z], u_c[4][it][x][y][z], sendar_y_T[x][(y)+(1)][z], sendar_y_B[x][(y)-(1)][z]);
BlockRetStatus block_316(CF &self)
{
	// wait params[x][y][z]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_c[4][it][x][y][z]
	if (self.wait(self.id(1)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=317;
	return CONTINUE;
}

// After requests: cf setBorder_y[x][y][z]: setBorder_y(params[x][y][z], u_c[4][it][x][y][z], sendar_y_T[x][(y)+(1)][z], sendar_y_B[x][(y)-(1)][z]);
BlockRetStatus block_317(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf setBorder_y[x][y][z]: setBorder_y(params[x][y][z], u_c[4][it][x][y][z], sendar_y_T[x][(y)+(1)][z], sendar_y_B[x][(y)-(1)][z]);
		setBorder_y(
			// value params[x][y][z]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[4][it][x][y][z]
			self.wait(self.id(1)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name sendar_y_T[x][(y)+(1)][z]
			_out_0, 
			// name sendar_y_B[x][(y)-(1)][z]
			_out_1);

		{
			DF stored=_out_0;
			self.store(self.id(2)[self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())+(1))][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(3)[self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())-(1))][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: sendar_y_T[x][(y)+(1)][z]
	{		DF posted=self.wait(self.id(2)[self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())+(1))][self.arg(2).get_int()]);
	self.post(self.id(2)[self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())+(1))][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>((self.arg(1).get_int())+(1)))*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: sendar_y_B[x][(y)-(1)][z]
	{		DF posted=self.wait(self.id(3)[self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())-(1))][self.arg(2).get_int()]);
	self.post(self.id(3)[self.arg(0).get_int()][static_cast<int>((self.arg(1).get_int())-(1))][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>((self.arg(1).get_int())-(1)))*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf setBorder_z[x][y][z]: setBorder_z(params[x][y][z], u_c[4][it][x][y][z], sendar_z_F[x][y][(z)+(1)], sendar_z_B[x][y][(z)-(1)]);
BlockRetStatus block_318(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request params[x][y][z]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u_c[4][it][x][y][z]
	self.request(self.id(1)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=319;
	return CONTINUE;
}

// Request : cf setBorder_z[x][y][z]: setBorder_z(params[x][y][z], u_c[4][it][x][y][z], sendar_z_F[x][y][(z)+(1)], sendar_z_B[x][y][(z)-(1)]);
BlockRetStatus block_319(CF &self)
{
	// wait params[x][y][z]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_c[4][it][x][y][z]
	if (self.wait(self.id(1)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=320;
	return CONTINUE;
}

// After requests: cf setBorder_z[x][y][z]: setBorder_z(params[x][y][z], u_c[4][it][x][y][z], sendar_z_F[x][y][(z)+(1)], sendar_z_B[x][y][(z)-(1)]);
BlockRetStatus block_320(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf setBorder_z[x][y][z]: setBorder_z(params[x][y][z], u_c[4][it][x][y][z], sendar_z_F[x][y][(z)+(1)], sendar_z_B[x][y][(z)-(1)]);
		setBorder_z(
			// value params[x][y][z]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[4][it][x][y][z]
			self.wait(self.id(1)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name sendar_z_F[x][y][(z)+(1)]
			_out_0, 
			// name sendar_z_B[x][y][(z)-(1)]
			_out_1);

		{
			DF stored=_out_0;
			self.store(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())+(1))], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())-(1))], stored);
		}
	}

	// req_unlimited: sendar_z_F[x][y][(z)+(1)]
	{		DF posted=self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())+(1))]);
	self.post(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())+(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>((self.arg(2).get_int())+(1)))))/(16))), -1);
	}
	// req_unlimited: sendar_z_B[x][y][(z)-(1)]
	{		DF posted=self.wait(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())-(1))]);
	self.post(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>((self.arg(2).get_int())-(1)))))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_321(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=322;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_322(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=323;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_323(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(324);
		child->arg(0)=_lc_y;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_324(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=325;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_325(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=326;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_326(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l347: vinit(sendar_x_R[0][y][z]);
		CF *child=self.fork(327);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->id(0)=self.id(1);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l347: vinit(sendar_x_R[0][y][z]);
BlockRetStatus block_327(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		// EXEC_EXTERN cf _l347: vinit(sendar_x_R[0][y][z]);
		c_vinit(
			// name sendar_x_R[0][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: sendar_x_R[0][y][z]
	{		DF posted=self.wait(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_328(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=329;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_329(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=330;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_330(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(331);
		child->arg(0)=_lc_y;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_331(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=332;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_332(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=333;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_333(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
		CF *child=self.fork(334);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
BlockRetStatus block_334(CF &self)
{
	// request_preliminary size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=335;
	return CONTINUE;
}

// RequestPreliminary : cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
BlockRetStatus block_335(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=336;
	return CONTINUE;
}

// After requests: cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
BlockRetStatus block_336(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=337;
	return CONTINUE;
}

// Request : cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
BlockRetStatus block_337(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=338;
	return CONTINUE;
}

// After requests: cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
BlockRetStatus block_338(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l353: vinit(sendar_x_L[(size_x)-(1)][y][z]);
		c_vinit(
			// name sendar_x_L[(size_x)-(1)][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: sendar_x_L[(size_x)-(1)][y][z]
	{		DF posted=self.wait(self.id(1)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(1)[static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_339(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=340;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_340(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=341;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_341(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(342);
		child->arg(0)=_lc_x;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_342(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=343;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_343(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=344;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_344(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l362: vinit(sendar_y_T[x][0][z]);
		CF *child=self.fork(345);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->id(0)=self.id(1);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l362: vinit(sendar_y_T[x][0][z]);
BlockRetStatus block_345(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		// EXEC_EXTERN cf _l362: vinit(sendar_y_T[x][0][z]);
		c_vinit(
			// name sendar_y_T[x][0][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0)[self.arg(0).get_int()][0][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: sendar_y_T[x][0][z]
	{		DF posted=self.wait(self.id(0)[self.arg(0).get_int()][0][self.arg(1).get_int()]);
	self.post(self.id(0)[self.arg(0).get_int()][0][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_346(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=347;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_347(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=348;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_348(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(349);
		child->arg(0)=_lc_x;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_349(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=350;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_350(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=351;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_351(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
		CF *child=self.fork(352);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
BlockRetStatus block_352(CF &self)
{
	// request_preliminary size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=353;
	return CONTINUE;
}

// RequestPreliminary : cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
BlockRetStatus block_353(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=354;
	return CONTINUE;
}

// After requests: cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
BlockRetStatus block_354(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=355;
	return CONTINUE;
}

// Request : cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
BlockRetStatus block_355(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=356;
	return CONTINUE;
}

// After requests: cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
BlockRetStatus block_356(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l369: vinit(sendar_y_B[x][(size_y)-(1)][z]);
		c_vinit(
			// name sendar_y_B[x][(size_y)-(1)][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: sendar_y_B[x][(size_y)-(1)][z]
	{		DF posted=self.wait(self.id(1)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()]);
	self.post(self.id(1)[self.arg(0).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_357(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=358;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_358(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=359;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_359(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(360);
		child->arg(0)=_lc_x;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // for
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_360(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=361;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_361(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=362;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_362(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: cf _l377: vinit(sendar_z_F[x][y][0]);
		CF *child=self.fork(363);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->id(0)=self.id(1);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l377: vinit(sendar_z_F[x][y][0]);
BlockRetStatus block_363(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		// EXEC_EXTERN cf _l377: vinit(sendar_z_F[x][y][0]);
		c_vinit(
			// name sendar_z_F[x][y][0]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][0], stored);
		}
	}

	// req_unlimited: sendar_z_F[x][y][0]
	{		DF posted=self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][0]);
	self.post(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][0], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_364(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=365;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_365(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=366;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_366(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(367);
		child->arg(0)=_lc_x;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	} // for
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_367(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=368;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_368(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=369;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_369(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
		CF *child=self.fork(370);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
BlockRetStatus block_370(CF &self)
{
	// request_preliminary size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=371;
	return CONTINUE;
}

// RequestPreliminary : cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
BlockRetStatus block_371(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=372;
	return CONTINUE;
}

// After requests: cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
BlockRetStatus block_372(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+((self.wait(self.id(0))).get_int())))-(1)))/(16))))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=373;
	return CONTINUE;
}

// Request : cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
BlockRetStatus block_373(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=374;
	return CONTINUE;
}

// After requests: cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
BlockRetStatus block_374(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l384: vinit(sendar_z_B[x][y][(size_z)-(1)]);
		c_vinit(
			// name sendar_z_B[x][y][(size_z)-(1)]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], stored);
		}
	}

	// req_unlimited: sendar_z_B[x][y][(size_z)-(1)]
	{		DF posted=self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]);
	self.post(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_375(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=376;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_376(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=377;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_377(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(378);
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
	}

	} // for
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_378(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=379;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_379(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=380;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_380(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(381);
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
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_381(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=382;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_382(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=383;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_383(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf loadBorder[x][y][z]: loadBorder(params[x][y][z], u_c[1][(it)+(1)][x][y][z], u_c[4][it][x][y][z], sendar_x_R[x][y][z], sendar_x_L[x][y][z], sendar_y_T[x][y][z], sendar_y_B[x][y][z], sendar_z_F[x][y][z], sendar_z_B[x][y][z]);
		CF *child=self.fork(384);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(8);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf loadBorder[x][y][z]: loadBorder(params[x][y][z], u_c[1][(it)+(1)][x][y][z], u_c[4][it][x][y][z], sendar_x_R[x][y][z], sendar_x_L[x][y][z], sendar_y_T[x][y][z], sendar_y_B[x][y][z], sendar_z_F[x][y][z], sendar_z_B[x][y][z]);
BlockRetStatus block_384(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request sendar_z_B[x][y][z]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request sendar_y_T[x][y][z]
	self.request(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request sendar_z_F[x][y][z]
	self.request(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u_c[4][it][x][y][z]
	self.request(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request sendar_x_R[x][y][z]
	self.request(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request sendar_x_L[x][y][z]
	self.request(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request sendar_y_B[x][y][z]
	self.request(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(7)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=385;
	return CONTINUE;
}

// Request : cf loadBorder[x][y][z]: loadBorder(params[x][y][z], u_c[1][(it)+(1)][x][y][z], u_c[4][it][x][y][z], sendar_x_R[x][y][z], sendar_x_L[x][y][z], sendar_y_T[x][y][z], sendar_y_B[x][y][z], sendar_z_F[x][y][z], sendar_z_B[x][y][z]);
BlockRetStatus block_385(CF &self)
{
	// wait sendar_z_B[x][y][z]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait sendar_y_T[x][y][z]
	if (self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait sendar_z_F[x][y][z]
	if (self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_c[4][it][x][y][z]
	if (self.wait(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait sendar_x_R[x][y][z]
	if (self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait sendar_x_L[x][y][z]
	if (self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait sendar_y_B[x][y][z]
	if (self.wait(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(7)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=386;
	return CONTINUE;
}

// After requests: cf loadBorder[x][y][z]: loadBorder(params[x][y][z], u_c[1][(it)+(1)][x][y][z], u_c[4][it][x][y][z], sendar_x_R[x][y][z], sendar_x_L[x][y][z], sendar_y_T[x][y][z], sendar_y_B[x][y][z], sendar_z_F[x][y][z], sendar_z_B[x][y][z]);
BlockRetStatus block_386(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf loadBorder[x][y][z]: loadBorder(params[x][y][z], u_c[1][(it)+(1)][x][y][z], u_c[4][it][x][y][z], sendar_x_R[x][y][z], sendar_x_L[x][y][z], sendar_y_T[x][y][z], sendar_y_B[x][y][z], sendar_z_F[x][y][z], sendar_z_B[x][y][z]);
		loadBorder(
			// value params[x][y][z]
			self.wait(self.id(7)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_c[1][(it)+(1)][x][y][z]
			_out_0, 
			// value u_c[4][it][x][y][z]
			self.wait(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value sendar_x_R[x][y][z]
			self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value sendar_x_L[x][y][z]
			self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value sendar_y_T[x][y][z]
			self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value sendar_y_B[x][y][z]
			self.wait(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value sendar_z_F[x][y][z]
			self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value sendar_z_B[x][y][z]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(3)[1][static_cast<int>((self.arg(3).get_int())+(1))][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(3)[4][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(3)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_c[1][(it)+(1)][x][y][z]
	{		DF posted=self.wait(self.id(3)[1][static_cast<int>((self.arg(3).get_int())+(1))][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[1][static_cast<int>((self.arg(3).get_int())+(1))][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// STRUCT: sub reduce_u(int cnt, int x, int y, int z, name u_cur, name u_c)
BlockRetStatus block_121(CF &self)
{
	Id _id_0=self.create_id(); // sums

// GEN BODY: sub reduce_u(int cnt, int x, int y, int z, name u_cur, name u_c)
	{ // FORK_BI: if (cnt)==(2)
		CF *child=self.fork(387);
		child->arg(0)=self.arg(1).get_int();
		child->arg(1)=self.arg(2).get_int();
		child->arg(2)=self.arg(3).get_int();
		child->arg(3)=self.arg(0).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	{ // FORK_BI: if (cnt)>(2)
		CF *child=self.fork(391);
		child->arg(0)=self.arg(1).get_int();
		child->arg(1)=self.arg(2).get_int();
		child->arg(2)=self.arg(3).get_int();
		child->arg(3)=self.arg(0).get_int();
		child->id(0)=self.id(0);
		child->id(1)=_id_0;
		child->id(2)=self.id(1);
	}

	return EXIT;
}

// IF: preparations: if (cnt)==(2)
BlockRetStatus block_387(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	if (0!=static_cast<int>((self.arg(3).get_int())==(2))) {

// GEN BODY: if (cnt)==(2)
	{ // FORK_BI: cf finaly_g[x][y][z]: gather_arr(u_cur[0][x][y][z], u_cur[1][x][y][z], u_c);
		CF *child=self.fork(388);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf finaly_g[x][y][z]: gather_arr(u_cur[0][x][y][z], u_cur[1][x][y][z], u_c);
BlockRetStatus block_388(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request u_cur[1][x][y][z]
	self.request(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	// request u_cur[0][x][y][z]
	self.request(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=389;
	return CONTINUE;
}

// Request : cf finaly_g[x][y][z]: gather_arr(u_cur[0][x][y][z], u_cur[1][x][y][z], u_c);
BlockRetStatus block_389(CF &self)
{
	// wait u_cur[1][x][y][z]
	if (self.wait(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_cur[0][x][y][z]
	if (self.wait(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=390;
	return CONTINUE;
}

// After requests: cf finaly_g[x][y][z]: gather_arr(u_cur[0][x][y][z], u_cur[1][x][y][z], u_c);
BlockRetStatus block_390(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf finaly_g[x][y][z]: gather_arr(u_cur[0][x][y][z], u_cur[1][x][y][z], u_c);
		gather_arr(
			// value u_cur[0][x][y][z]
			self.wait(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_cur[1][x][y][z]
			self.wait(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_c
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1), stored);
		}
	}

	self.destroy(self.id(0)[0][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	self.destroy(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	// req_unlimited: u_c
	{		DF posted=self.wait(self.id(1));
	self.post(self.id(1), posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// IF: preparations: if (cnt)>(2)
BlockRetStatus block_391(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	if (0!=static_cast<int>((self.arg(3).get_int())>(2))) {

// GEN BODY: if (cnt)>(2)
	{ // FORK_BI: if ((cnt)%(2))==(0)
		CF *child=self.fork(392);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
		child->id(2)=self.id(2);
	}

	{ // FORK_BI: if ((cnt)%(2))!=(0)
		CF *child=self.fork(398);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
		child->id(2)=self.id(2);
	}

	} // if
	return EXIT;
}

// IF: preparations: if ((cnt)%(2))==(0)
BlockRetStatus block_392(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	if (0!=static_cast<int>((static_cast<int>((self.arg(3).get_int())%(2)))==(0))) {

// GEN BODY: if ((cnt)%(2))==(0)
	{ // FORK_BI: for i=0..((cnt)/(2))-(1);
		CF *child=self.fork(393);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	{ // FORK_BI: cf _l55: reduce_u((cnt)/(2), x, y, z, sums, u_c);
		CF *child=self.fork(397);
		child->arg(0)=self.arg(3).get_int();
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // if
	return EXIT;
}

// BI_FOR: for i = 0 .. ((cnt)/(2))-(1)
BlockRetStatus block_393(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	for (int _lc_i=0; _lc_i<=static_cast<int>((static_cast<int>((self.arg(3).get_int())/(2)))-(1)); _lc_i++) {

// GEN BODY: for i = 0 .. ((cnt)/(2))-(1)
	{ // FORK_BI: cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
		CF *child=self.fork(394);
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
BlockRetStatus block_394(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request u_cur[((i)*(2))+(1)][x][y][z]
	self.request(self.id(0)[static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))+(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));
	// request u_cur[(i)*(2)][x][y][z]
	self.request(self.id(0)[static_cast<int>((self.arg(0).get_int())*(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()], CyclicLocator(0));

	self.NextBlock=395;
	return CONTINUE;
}

// Request : cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
BlockRetStatus block_395(CF &self)
{
	// wait u_cur[((i)*(2))+(1)][x][y][z]
	if (self.wait(self.id(0)[static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))+(1))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_cur[(i)*(2)][x][y][z]
	if (self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())*(2))][self.arg(1).get_int()][self.arg(2).get_int()][self.arg(3).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=396;
	return CONTINUE;
}

// After requests: cf gather[i][x][y][z]: gather_arr(u_cur[(i)*(2)][x][y][z], u_cur[((i)*(2))+(1)][x][y][z], sums[i][x][y][z]);
BlockRetStatus block_396(CF &self)
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

// BI_EXEC: cf _l55: reduce_u((cnt)/(2), x, y, z, sums, u_c);
BlockRetStatus block_397(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	{ // EXEC_STRUCT: cf _l55: reduce_u((cnt)/(2), x, y, z, sums, u_c);
		CF *child=self.fork(121);
		child->arg(0)=static_cast<int>((self.arg(0).get_int())/(2));
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	return EXIT;
}

// IF: preparations: if ((cnt)%(2))!=(0)
BlockRetStatus block_398(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	if (0!=static_cast<int>((static_cast<int>((self.arg(3).get_int())%(2)))!=(0))) {

// GEN BODY: if ((cnt)%(2))!=(0)
	{ // FORK_BI: for i=0..((cnt)/(2))-(1);
		CF *child=self.fork(399);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	{ // FORK_BI: cf copy_g[(cnt)/(2)][x][y][z]: copy_v(u_cur[(cnt)-(1)][x][y][z], sums[(cnt)/(2)][x][y][z]);
		CF *child=self.fork(403);
		child->arg(0)=self.arg(3).get_int();
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(1);
	}

	{ // FORK_BI: cf _l62: reduce_u(((cnt)/(2))+(1), x, y, z, sums, u_c);
		CF *child=self.fork(406);
		child->arg(0)=self.arg(3).get_int();
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	} // if
	return EXIT;
}

// BI_FOR: for i = 0 .. ((cnt)/(2))-(1)