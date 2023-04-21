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

BlockRetStatus block_200(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=201;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_201(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(202);
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
BlockRetStatus block_202(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=203;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_203(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=204;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_204(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(205);
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
BlockRetStatus block_205(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=206;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_206(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=207;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_207(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l251: reduce_u(cntfor[2][x][y][z], x, y, z, u_cur[2][it], u[2][it][x][y][z]);
		CF *child=self.fork(208);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	{ // FORK_BI: cf fill_u_x[x][y][z]: fill_u(2, cntstep[2][x][y][z], params[x][y][z], u[2][it][x][y][z], u_c[3][it][x][y][z]);
		CF *child=self.fork(211);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(4);
		child->id(1)=self.id(3);
		child->id(2)=self.id(5);
		child->id(3)=self.id(6);
		child->id(4)=self.id(7);
		child->id(5)=self.id(8);
		child->id(6)=self.id(9);
		child->id(7)=self.id(10);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf _l251: reduce_u(cntfor[2][x][y][z], x, y, z, u_cur[2][it], u[2][it][x][y][z]);
BlockRetStatus block_208(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[2][x][y][z]
	self.request(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=209;
	return CONTINUE;
}

// Request : cf _l251: reduce_u(cntfor[2][x][y][z], x, y, z, u_cur[2][it], u[2][it][x][y][z]);
BlockRetStatus block_209(CF &self)
{
	// wait cntfor[2][x][y][z]
	if (self.wait(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=210;
	return CONTINUE;
}

// After requests: cf _l251: reduce_u(cntfor[2][x][y][z], x, y, z, u_cur[2][it], u[2][it][x][y][z]);
BlockRetStatus block_210(CF &self)
{
	{ // EXEC_STRUCT: cf _l251: reduce_u(cntfor[2][x][y][z], x, y, z, u_cur[2][it], u[2][it][x][y][z]);
		CF *child=self.fork(121);
		child->arg(0)=self.wait(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int();
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1)[2][self.arg(3).get_int()];
		child->id(1)=self.id(2)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()];
	}

	return EXIT;
}

// BI_EXEC: cf fill_u_x[x][y][z]: fill_u(2, cntstep[2][x][y][z], params[x][y][z], u[2][it][x][y][z], u_c[3][it][x][y][z]);
BlockRetStatus block_211(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[2][x][y][z]
	self.request(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u[2][it][x][y][z]
	self.request(self.id(1)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	// request params[x][y][z]
	self.request(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=212;
	return CONTINUE;
}

// Request : cf fill_u_x[x][y][z]: fill_u(2, cntstep[2][x][y][z], params[x][y][z], u[2][it][x][y][z], u_c[3][it][x][y][z]);
BlockRetStatus block_212(CF &self)
{
	// wait cntstep[2][x][y][z]
	if (self.wait(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u[2][it][x][y][z]
	if (self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=213;
	return CONTINUE;
}

// After requests: cf fill_u_x[x][y][z]: fill_u(2, cntstep[2][x][y][z], params[x][y][z], u[2][it][x][y][z], u_c[3][it][x][y][z]);
BlockRetStatus block_213(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf fill_u_x[x][y][z]: fill_u(2, cntstep[2][x][y][z], params[x][y][z], u[2][it][x][y][z], u_c[3][it][x][y][z]);
		fill_u(
			// int 2
			2, 
			// int cntstep[2][x][y][z]
			self.wait(self.id(0)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u[2][it][x][y][z]
			self.wait(self.id(1)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_c[3][it][x][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(1)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));
	self.destroy(self.id(4)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(5)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(6)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(7)[2][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_c[3][it][x][y][z]
	{		DF posted=self.wait(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_214(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=215;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_215(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=216;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_216(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(217);
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

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_217(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=218;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_218(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=219;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_219(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: cf init_alfa_beta_z[x][y][0]: init_alfa_beta(cntstep[3][x][y][0], alfa_beta_beg[3][it][x][y][0]);
		CF *child=self.fork(220);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(223);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(3);
		child->id(1)=self.id(4);
		child->id(2)=self.id(5);
		child->id(3)=self.id(6);
		child->id(4)=self.id(7);
		child->id(5)=self.id(8);
		child->id(6)=self.id(9);
	}

	{ // FORK_BI: cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
		CF *child=self.fork(229);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(3);
		child->id(1)=self.id(1);
		child->id(2)=self.id(10);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf init_alfa_beta_z[x][y][0]: init_alfa_beta(cntstep[3][x][y][0], alfa_beta_beg[3][it][x][y][0]);
BlockRetStatus block_220(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[3][x][y][0]
	self.request(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));

	self.NextBlock=221;
	return CONTINUE;
}

// Request : cf init_alfa_beta_z[x][y][0]: init_alfa_beta(cntstep[3][x][y][0], alfa_beta_beg[3][it][x][y][0]);
BlockRetStatus block_221(CF &self)
{
	// wait cntstep[3][x][y][0]
	if (self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=222;
	return CONTINUE;
}

// After requests: cf init_alfa_beta_z[x][y][0]: init_alfa_beta(cntstep[3][x][y][0], alfa_beta_beg[3][it][x][y][0]);
BlockRetStatus block_222(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf init_alfa_beta_z[x][y][0]: init_alfa_beta(cntstep[3][x][y][0], alfa_beta_beg[3][it][x][y][0]);
		init_alfa_beta(
			// int cntstep[3][x][y][0]
			self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).get_int(), 
			// name alfa_beta_beg[3][it][x][y][0]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], stored);
		}
	}

	// req_unlimited: alfa_beta_beg[3][it][x][y][0]
	{		DF posted=self.wait(self.id(1)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]);
	self.post(self.id(1)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_223(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=224;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_224(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=225;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_225(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf calcCoef_z[x][y][z]: calcCoef_z(params[x][y][z], u_c[1][it][x][y][z], u_c[3][it][x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z]);
		CF *child=self.fork(226);
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
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calcCoef_z[x][y][z]: calcCoef_z(params[x][y][z], u_c[1][it][x][y][z], u_c[3][it][x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z]);
BlockRetStatus block_226(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request u_c[1][it][x][y][z]
	self.request(self.id(0)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u_c[3][it][x][y][z]
	self.request(self.id(0)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=227;
	return CONTINUE;
}

// Request : cf calcCoef_z[x][y][z]: calcCoef_z(params[x][y][z], u_c[1][it][x][y][z], u_c[3][it][x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z]);
BlockRetStatus block_227(CF &self)
{
	// wait u_c[1][it][x][y][z]
	if (self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_c[3][it][x][y][z]
	if (self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=228;
	return CONTINUE;
}

// After requests: cf calcCoef_z[x][y][z]: calcCoef_z(params[x][y][z], u_c[1][it][x][y][z], u_c[3][it][x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z]);
BlockRetStatus block_228(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		DF _out_3;
		// EXEC_EXTERN cf calcCoef_z[x][y][z]: calcCoef_z(params[x][y][z], u_c[1][it][x][y][z], u_c[3][it][x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z]);
		calcCoef_z(
			// value params[x][y][z]
			self.wait(self.id(1)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[1][it][x][y][z]
			self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[3][it][x][y][z]
			self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name a[3][it][x][y][z]
			_out_0, 
			// name b[3][it][x][y][z]
			_out_1, 
			// name c[3][it][x][y][z]
			_out_2, 
			// name f[3][it][x][y][z]
			_out_3);

		{
			DF stored=_out_0;
			self.store(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(4)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_3;
			self.store(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: a[3][it][x][y][z]
	{		DF posted=self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: b[3][it][x][y][z]
	{		DF posted=self.wait(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: c[3][it][x][y][z]
	{		DF posted=self.wait(self.id(4)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: f[3][it][x][y][z]
	{		DF posted=self.wait(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_229(CF &self)
{
	// request_preliminary size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=230;
	return CONTINUE;
}

// RequestPreliminary : cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_230(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=231;
	return CONTINUE;
}

// After requests: cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_231(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+((self.wait(self.id(0))).get_int())))-(1)))/(16))))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=232;
	return CONTINUE;
}

// Request : cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_232(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=233;
	return CONTINUE;
}

// After requests: cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_233(CF &self)
{
	// request cntstep[3][x][y][(size_z)-(1)]
	self.request(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));

	self.NextBlock=234;
	return CONTINUE;
}

// Request : cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_234(CF &self)
{
	// wait cntstep[3][x][y][(size_z)-(1)]
	if (self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=235;
	return CONTINUE;
}

// After requests: cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_235(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf init_uend_z[x][y][(size_z)-(1)]: init_uend(cntstep[3][x][y][(size_z)-(1)], ubeg[3][it][x][y][(size_z)-(1)]);
		init_uend(
			// int cntstep[3][x][y][(size_z)-(1)]
			self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).get_int(), 
			// name ubeg[3][it][x][y][(size_z)-(1)]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(2)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], stored);
		}
	}

	// req_unlimited: ubeg[3][it][x][y][(size_z)-(1)]
	{		DF posted=self.wait(self.id(2)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]);
	self.post(self.id(2)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_236(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=237;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_237(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=238;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_238(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(239);
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
		child->id(13)=self.id(0);
		child->id(14)=self.id(14);
		child->id(15)=self.id(15);
		child->id(16)=self.id(16);
	}

	} // for
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_239(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=240;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_240(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=241;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_241(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for i=0..(cntfor[3][x][y][0])-(1);
		CF *child=self.fork(242);
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
		child->id(11)=self.id(12);
		child->id(12)=self.id(13);
		child->id(13)=self.id(14);
		child->id(14)=self.id(15);
	}

	{ // FORK_BI: for z=1..(size_z)-(2);
		CF *child=self.fork(254);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(12);
		child->id(1)=self.id(1);
		child->id(2)=self.id(11);
		child->id(3)=self.id(7);
		child->id(4)=self.id(6);
		child->id(5)=self.id(3);
		child->id(6)=self.id(5);
		child->id(7)=self.id(4);
		child->id(8)=self.id(8);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(14);
		child->id(12)=self.id(0);
		child->id(13)=self.id(13);
		child->id(14)=self.id(15);
	}

	{ // FORK_BI: for i=0..(cntfor[3][x][y][(size_z)-(1)])-(1);
		CF *child=self.fork(266);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_y;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(12);
		child->id(1)=self.id(1);
		child->id(2)=self.id(8);
		child->id(3)=self.id(3);
		child->id(4)=self.id(7);
		child->id(5)=self.id(11);
		child->id(6)=self.id(5);
		child->id(7)=self.id(4);
		child->id(8)=self.id(6);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(0);
		child->id(12)=self.id(13);
		child->id(13)=self.id(16);
		child->id(14)=self.id(15);
		child->id(15)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_FOR: for i = 0 .. (cntfor[3][x][y][0])-(1)
BlockRetStatus block_242(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[3][x][y][0]
	self.request(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(0));

	self.NextBlock=243;
	return CONTINUE;
}

// Request : for i = 0 .. (cntfor[3][x][y][0])-(1)
BlockRetStatus block_243(CF &self)
{
	// wait cntfor[3][x][y][0]
	if (self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=244;
	return CONTINUE;
}

// After requests: for i = 0 .. (cntfor[3][x][y][0])-(1)
BlockRetStatus block_244(CF &self)
{
	for (int _lc_i=0; _lc_i<=static_cast<int>((self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).get_int())-(1)); _lc_i++) {

// GEN BODY: for i = 0 .. (cntfor[3][x][y][0])-(1)
	{ // FORK_BI: cf calccoef_pr_z[i][x][y][0]: calccoef_pr_z(cntstep[3][x][y][0], i, params[x][y][0], a[3][it][x][y][0], b[3][it][x][y][0], c[3][it][x][y][0], f[3][it][x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], alfa_beta_beg[3][it][x][y][0], alfa_beta_beg6[3][it][i][x][y][1]);
		CF *child=self.fork(245);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_i;
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

	{ // FORK_BI: if (size_z)>(1)
		CF *child=self.fork(248);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_i;
		child->id(0)=self.id(11);
		child->id(1)=self.id(2);
		child->id(2)=self.id(12);
		child->id(3)=self.id(8);
		child->id(4)=self.id(9);
		child->id(5)=self.id(13);
		child->id(6)=self.id(4);
		child->id(7)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_z[i][x][y][0]: calccoef_pr_z(cntstep[3][x][y][0], i, params[x][y][0], a[3][it][x][y][0], b[3][it][x][y][0], c[3][it][x][y][0], f[3][it][x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], alfa_beta_beg[3][it][x][y][0], alfa_beta_beg6[3][it][i][x][y][1]);
BlockRetStatus block_245(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))))) {
		return MIGRATE;
	}

	// request alfa_beta_beg[3][it][x][y][0]
	self.request(self.id(0)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request cntstep[3][x][y][0]
	self.request(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request a[3][it][x][y][0]
	self.request(self.id(2)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request params[x][y][0]
	self.request(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request c[3][it][x][y][0]
	self.request(self.id(4)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request f[3][it][x][y][0]
	self.request(self.id(5)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request b[3][it][x][y][0]
	self.request(self.id(6)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));

	self.NextBlock=246;
	return CONTINUE;
}

// Request : cf calccoef_pr_z[i][x][y][0]: calccoef_pr_z(cntstep[3][x][y][0], i, params[x][y][0], a[3][it][x][y][0], b[3][it][x][y][0], c[3][it][x][y][0], f[3][it][x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], alfa_beta_beg[3][it][x][y][0], alfa_beta_beg6[3][it][i][x][y][1]);
BlockRetStatus block_246(CF &self)
{
	// wait alfa_beta_beg[3][it][x][y][0]
	if (self.wait(self.id(0)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[3][x][y][0]
	if (self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait a[3][it][x][y][0]
	if (self.wait(self.id(2)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][0]
	if (self.wait(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait c[3][it][x][y][0]
	if (self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait f[3][it][x][y][0]
	if (self.wait(self.id(5)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait b[3][it][x][y][0]
	if (self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=247;
	return CONTINUE;
}

// After requests: cf calccoef_pr_z[i][x][y][0]: calccoef_pr_z(cntstep[3][x][y][0], i, params[x][y][0], a[3][it][x][y][0], b[3][it][x][y][0], c[3][it][x][y][0], f[3][it][x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], alfa_beta_beg[3][it][x][y][0], alfa_beta_beg6[3][it][i][x][y][1]);
BlockRetStatus block_247(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_z[i][x][y][0]: calccoef_pr_z(cntstep[3][x][y][0], i, params[x][y][0], a[3][it][x][y][0], b[3][it][x][y][0], c[3][it][x][y][0], f[3][it][x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], alfa_beta_beg[3][it][x][y][0], alfa_beta_beg6[3][it][i][x][y][1]);
		calccoef_pr_z(
			// int cntstep[3][x][y][0]
			self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).get_int(), 
			// int i
			self.arg(3).get_int(), 
			// value params[x][y][0]
			self.wait(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// value a[3][it][x][y][0]
			self.wait(self.id(2)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// value b[3][it][x][y][0]
			self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// value c[3][it][x][y][0]
			self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// value f[3][it][x][y][0]
			self.wait(self.id(5)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// name alfa[3][it][i][x][y][0]
			_out_0, 
			// name beta[3][it][i][x][y][0]
			_out_1, 
			// value alfa_beta_beg[3][it][x][y][0]
			self.wait(self.id(0)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// name alfa_beta_beg6[3][it][i][x][y][1]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][1], stored);
		}
	}

	// req_unlimited: alfa[3][it][i][x][y][0]
	{		DF posted=self.wait(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]);
	self.post(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))), -1);
	}
	// req_unlimited: beta[3][it][i][x][y][0]
	{		DF posted=self.wait(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]);
	self.post(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[3][it][i][x][y][1]
	{		DF posted=self.wait(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][1]);
	self.post(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][1], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(1)))/(16))), -1);
	}
	return EXIT;
}

// IF: preparations: if (size_z)>(1)
BlockRetStatus block_248(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=249;
	return CONTINUE;
}

// Request : if (size_z)>(1)
BlockRetStatus block_249(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=250;
	return CONTINUE;
}

// After requests: if (size_z)>(1)
BlockRetStatus block_250(CF &self)
{
	if (0!=static_cast<int>(((self.wait(self.id(0))).get_int())>(1))) {

// GEN BODY: if (size_z)>(1)
	{ // FORK_BI: cf calcVal_z[i][x][y][0]: calcVal(((y)*(size_x))+(x), 3, cntstep[3][x][y][0], params[x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], u_cur[3][it][i][x][y][0], ubeg6[3][it][i][x][y][(0)-(1)], ubeg6[3][it][i][x][y][0]);
		CF *child=self.fork(251);
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
		child->id(6)=self.id(7);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf calcVal_z[i][x][y][0]: calcVal(((y)*(size_x))+(x), 3, cntstep[3][x][y][0], params[x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], u_cur[3][it][i][x][y][0], ubeg6[3][it][i][x][y][(0)-(1)], ubeg6[3][it][i][x][y][0]);
BlockRetStatus block_251(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[3][x][y][0]
	self.request(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request size_x
	self.request(self.id(1), CyclicLocator(0));
	// request alfa[3][it][i][x][y][0]
	self.request(self.id(2)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request beta[3][it][i][x][y][0]
	self.request(self.id(3)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request ubeg6[3][it][i][x][y][0]
	self.request(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	// request params[x][y][0]
	self.request(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));

	self.NextBlock=252;
	return CONTINUE;
}

// Request : cf calcVal_z[i][x][y][0]: calcVal(((y)*(size_x))+(x), 3, cntstep[3][x][y][0], params[x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], u_cur[3][it][i][x][y][0], ubeg6[3][it][i][x][y][(0)-(1)], ubeg6[3][it][i][x][y][0]);
BlockRetStatus block_252(CF &self)
{
	// wait cntstep[3][x][y][0]
	if (self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait alfa[3][it][i][x][y][0]
	if (self.wait(self.id(2)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait beta[3][it][i][x][y][0]
	if (self.wait(self.id(3)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait ubeg6[3][it][i][x][y][0]
	if (self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][0]
	if (self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][0]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=253;
	return CONTINUE;
}

// After requests: cf calcVal_z[i][x][y][0]: calcVal(((y)*(size_x))+(x), 3, cntstep[3][x][y][0], params[x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], u_cur[3][it][i][x][y][0], ubeg6[3][it][i][x][y][(0)-(1)], ubeg6[3][it][i][x][y][0]);
BlockRetStatus block_253(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_z[i][x][y][0]: calcVal(((y)*(size_x))+(x), 3, cntstep[3][x][y][0], params[x][y][0], alfa[3][it][i][x][y][0], beta[3][it][i][x][y][0], u_cur[3][it][i][x][y][0], ubeg6[3][it][i][x][y][(0)-(1)], ubeg6[3][it][i][x][y][0]);
		calcVal(
			// int ((y)*(size_x))+(x)
			static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(1))).get_int())))+(self.arg(0).get_int())), 
			// int 3
			3, 
			// int cntstep[3][x][y][0]
			self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][0]).get_int(), 
			// value params[x][y][0]
			self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// value alfa[3][it][i][x][y][0]
			self.wait(self.id(2)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// value beta[3][it][i][x][y][0]
			self.wait(self.id(3)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]), 
			// name u_cur[3][it][i][x][y][0]
			_out_0, 
			// name ubeg6[3][it][i][x][y][(0)-(1)]
			_out_1, 
			// value ubeg6[3][it][i][x][y][0]
			self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]));

		{
			DF stored=_out_0;
			self.store(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((0)-(1))], stored);
		}
	}

	self.destroy(self.id(2)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	self.destroy(self.id(3)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	self.destroy(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(0)))/(16))));
	self.destroy(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((0)-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>((0)-(1)))))/(16))));
	// req_unlimited: u_cur[3][it][i][x][y][0]
	{		DF posted=self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0]);
	self.post(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][0], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[3][it][i][x][y][(0)-(1)]
	{		DF posted=self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((0)-(1))]);
	self.post(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((0)-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>((0)-(1)))))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for z = 1 .. (size_z)-(2)
BlockRetStatus block_254(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=255;
	return CONTINUE;
}

// Request : for z = 1 .. (size_z)-(2)
BlockRetStatus block_255(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=256;
	return CONTINUE;
}

// After requests: for z = 1 .. (size_z)-(2)
BlockRetStatus block_256(CF &self)
{
	for (int _lc_z=1; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(2)); _lc_z++) {

// GEN BODY: for z = 1 .. (size_z)-(2)
	{ // FORK_BI: for i=0..(cntfor[3][x][y][z])-(1);
		CF *child=self.fork(257);
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
		child->id(8)=self.id(9);
		child->id(9)=self.id(10);
		child->id(10)=self.id(11);
		child->id(11)=self.id(0);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_FOR: for i = 0 .. (cntfor[3][x][y][z])-(1)
BlockRetStatus block_257(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[3][x][y][z]
	self.request(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=258;
	return CONTINUE;
}

// Request : for i = 0 .. (cntfor[3][x][y][z])-(1)
BlockRetStatus block_258(CF &self)
{
	// wait cntfor[3][x][y][z]
	if (self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=259;
	return CONTINUE;
}

// After requests: for i = 0 .. (cntfor[3][x][y][z])-(1)
BlockRetStatus block_259(CF &self)
{
	for (int _lc_i=0; _lc_i<=static_cast<int>((self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int())-(1)); _lc_i++) {

// GEN BODY: for i = 0 .. (cntfor[3][x][y][z])-(1)
	{ // FORK_BI: cf calccoef_pr_z[i][x][y][z]: calccoef_pr_z(cntstep[3][x][y][z], i, params[x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][(z)+(1)]);
		CF *child=self.fork(260);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->arg(4)=_lc_i;
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

	{ // FORK_BI: cf calcVal_z[i][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][z], params[x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], u_cur[3][it][i][x][y][z], ubeg6[3][it][i][x][y][(z)-(1)], ubeg6[3][it][i][x][y][z]);
		CF *child=self.fork(263);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->arg(4)=_lc_i;
		child->id(0)=self.id(10);
		child->id(1)=self.id(4);
		child->id(2)=self.id(8);
		child->id(3)=self.id(11);
		child->id(4)=self.id(12);
		child->id(5)=self.id(5);
		child->id(6)=self.id(9);
		child->id(7)=self.id(13);
		child->id(8)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_z[i][x][y][z]: calccoef_pr_z(cntstep[3][x][y][z], i, params[x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][(z)+(1)]);
BlockRetStatus block_260(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request alfa_beta_beg6[3][it][i][x][y][z]
	self.request(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request f[3][it][x][y][z]
	self.request(self.id(1)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request c[3][it][x][y][z]
	self.request(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request cntstep[3][x][y][z]
	self.request(self.id(3)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request a[3][it][x][y][z]
	self.request(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request b[3][it][x][y][z]
	self.request(self.id(6)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=261;
	return CONTINUE;
}

// Request : cf calccoef_pr_z[i][x][y][z]: calccoef_pr_z(cntstep[3][x][y][z], i, params[x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][(z)+(1)]);
BlockRetStatus block_261(CF &self)
{
	// wait alfa_beta_beg6[3][it][i][x][y][z]
	if (self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[3][it][x][y][z]
	if (self.wait(self.id(1)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[3][it][x][y][z]
	if (self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[3][x][y][z]
	if (self.wait(self.id(3)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait a[3][it][x][y][z]
	if (self.wait(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait b[3][it][x][y][z]
	if (self.wait(self.id(6)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=262;
	return CONTINUE;
}

// After requests: cf calccoef_pr_z[i][x][y][z]: calccoef_pr_z(cntstep[3][x][y][z], i, params[x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][(z)+(1)]);
BlockRetStatus block_262(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_z[i][x][y][z]: calccoef_pr_z(cntstep[3][x][y][z], i, params[x][y][z], a[3][it][x][y][z], b[3][it][x][y][z], c[3][it][x][y][z], f[3][it][x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][z], alfa_beta_beg6[3][it][i][x][y][(z)+(1)]);
		calccoef_pr_z(
			// int cntstep[3][x][y][z]
			self.wait(self.id(3)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// int i
			self.arg(4).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value a[3][it][x][y][z]
			self.wait(self.id(5)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value b[3][it][x][y][z]
			self.wait(self.id(6)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value c[3][it][x][y][z]
			self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value f[3][it][x][y][z]
			self.wait(self.id(1)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name alfa[3][it][i][x][y][z]
			_out_0, 
			// name beta[3][it][i][x][y][z]
			_out_1, 
			// value alfa_beta_beg6[3][it][i][x][y][z]
			self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name alfa_beta_beg6[3][it][i][x][y][(z)+(1)]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(7)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(8)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())+(1))], stored);
		}
	}

	self.destroy(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: alfa[3][it][i][x][y][z]
	{		DF posted=self.wait(self.id(7)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(7)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[3][it][i][x][y][z]
	{		DF posted=self.wait(self.id(8)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(8)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[3][it][i][x][y][(z)+(1)]
	{		DF posted=self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())+(1))]);
	self.post(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())+(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>((self.arg(2).get_int())+(1)))))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf calcVal_z[i][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][z], params[x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], u_cur[3][it][i][x][y][z], ubeg6[3][it][i][x][y][(z)-(1)], ubeg6[3][it][i][x][y][z]);
BlockRetStatus block_263(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request ubeg6[3][it][i][x][y][z]
	self.request(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request cntstep[3][x][y][z]
	self.request(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request alfa[3][it][i][x][y][z]
	self.request(self.id(2)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_z
	self.request(self.id(3), CyclicLocator(0));
	// request size_y
	self.request(self.id(4), CyclicLocator(0));
	// request params[x][y][z]
	self.request(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request beta[3][it][i][x][y][z]
	self.request(self.id(6)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_x
	self.request(self.id(7), CyclicLocator(0));

	self.NextBlock=264;
	return CONTINUE;
}

// Request : cf calcVal_z[i][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][z], params[x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], u_cur[3][it][i][x][y][z], ubeg6[3][it][i][x][y][(z)-(1)], ubeg6[3][it][i][x][y][z]);
BlockRetStatus block_264(CF &self)
{
	// wait ubeg6[3][it][i][x][y][z]
	if (self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[3][x][y][z]
	if (self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa[3][it][i][x][y][z]
	if (self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(3)).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(4)).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait beta[3][it][i][x][y][z]
	if (self.wait(self.id(6)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(7)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=265;
	return CONTINUE;
}

// After requests: cf calcVal_z[i][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][z], params[x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], u_cur[3][it][i][x][y][z], ubeg6[3][it][i][x][y][(z)-(1)], ubeg6[3][it][i][x][y][z]);
BlockRetStatus block_265(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_z[i][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][z], params[x][y][z], alfa[3][it][i][x][y][z], beta[3][it][i][x][y][z], u_cur[3][it][i][x][y][z], ubeg6[3][it][i][x][y][(z)-(1)], ubeg6[3][it][i][x][y][z]);
		calcVal(
			// int ((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(4))).get_int())))*((self.wait(self.id(3))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(7))).get_int())))))+(self.arg(0).get_int())), 
			// int 3
			3, 
			// int cntstep[3][x][y][z]
			self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value alfa[3][it][i][x][y][z]
			self.wait(self.id(2)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value beta[3][it][i][x][y][z]
			self.wait(self.id(6)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_cur[3][it][i][x][y][z]
			_out_0, 
			// name ubeg6[3][it][i][x][y][(z)-(1)]
			_out_1, 
			// value ubeg6[3][it][i][x][y][z]
			self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())-(1))], stored);
		}
	}

	self.destroy(self.id(2)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(6)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_cur[3][it][i][x][y][z]
	{		DF posted=self.wait(self.id(8)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(8)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[3][it][i][x][y][(z)-(1)]
	{		DF posted=self.wait(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())-(1))]);
	self.post(self.id(0)[3][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>((self.arg(2).get_int())-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>((self.arg(2).get_int())-(1)))))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for i = 0 .. (cntfor[3][x][y][(size_z)-(1)])-(1)
BlockRetStatus block_266(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=267;
	return CONTINUE;
}

// Request : for i = 0 .. (cntfor[3][x][y][(size_z)-(1)])-(1)
BlockRetStatus block_267(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=268;
	return CONTINUE;
}

// After requests: for i = 0 .. (cntfor[3][x][y][(size_z)-(1)])-(1)
BlockRetStatus block_268(CF &self)
{
	// request cntfor[3][x][y][(size_z)-(1)]
	self.request(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(0));

	self.NextBlock=269;
	return CONTINUE;
}

// Request : for i = 0 .. (cntfor[3][x][y][(size_z)-(1)])-(1)
BlockRetStatus block_269(CF &self)
{
	// wait cntfor[3][x][y][(size_z)-(1)]
	if (self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=270;
	return CONTINUE;
}

// After requests: for i = 0 .. (cntfor[3][x][y][(size_z)-(1)])-(1)
BlockRetStatus block_270(CF &self)
{
	for (int _lc_i=0; _lc_i<=static_cast<int>((self.wait(self.id(1)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).get_int())-(1)); _lc_i++) {

// GEN BODY: for i = 0 .. (cntfor[3][x][y][(size_z)-(1)])-(1)
	{ // FORK_BI: if (size_z)>(1)
		CF *child=self.fork(271);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_i;
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

	{ // FORK_BI: cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
		CF *child=self.fork(281);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_i;
		child->id(0)=self.id(0);
		child->id(1)=self.id(11);
		child->id(2)=self.id(12);
		child->id(3)=self.id(13);
		child->id(4)=self.id(6);
		child->id(5)=self.id(3);
		child->id(6)=self.id(10);
		child->id(7)=self.id(9);
		child->id(8)=self.id(14);
		child->id(9)=self.id(15);
	}

	} // for
	return EXIT;
}

// IF: preparations: if (size_z)>(1)
BlockRetStatus block_271(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=272;
	return CONTINUE;
}

// Request : if (size_z)>(1)
BlockRetStatus block_272(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=273;
	return CONTINUE;
}

// After requests: if (size_z)>(1)
BlockRetStatus block_273(CF &self)
{
	if (0!=static_cast<int>(((self.wait(self.id(0))).get_int())>(1))) {

// GEN BODY: if (size_z)>(1)
	{ // FORK_BI: cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
		CF *child=self.fork(274);
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

// BI_EXEC: cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_274(CF &self)
{
	// request_preliminary size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=275;
	return CONTINUE;
}

// RequestPreliminary : cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_275(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=276;
	return CONTINUE;
}

// After requests: cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_276(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+((self.wait(self.id(0))).get_int())))-(1)))/(16))))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=277;
	return CONTINUE;
}

// Request : cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_277(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=278;
	return CONTINUE;
}

// After requests: cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_278(CF &self)
{
	// request b[3][it][x][y][(size_z)-(1)]
	self.request(self.id(1)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request cntstep[3][x][y][(size_z)-(1)]
	self.request(self.id(2)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request f[3][it][x][y][(size_z)-(1)]
	self.request(self.id(3)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)]
	self.request(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request params[x][y][(size_z)-(1)]
	self.request(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request a[3][it][x][y][(size_z)-(1)]
	self.request(self.id(6)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request c[3][it][x][y][(size_z)-(1)]
	self.request(self.id(7)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));

	self.NextBlock=279;
	return CONTINUE;
}

// Request : cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_279(CF &self)
{
	// wait b[3][it][x][y][(size_z)-(1)]
	if (self.wait(self.id(1)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[3][x][y][(size_z)-(1)]
	if (self.wait(self.id(2)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait f[3][it][x][y][(size_z)-(1)]
	if (self.wait(self.id(3)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)]
	if (self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][(size_z)-(1)]
	if (self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait a[3][it][x][y][(size_z)-(1)]
	if (self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait c[3][it][x][y][(size_z)-(1)]
	if (self.wait(self.id(7)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=280;
	return CONTINUE;
}

// After requests: cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
BlockRetStatus block_280(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_z[i][x][y][(size_z)-(1)]: calccoef_pr_z(cntstep[3][x][y][(size_z)-(1)], i, params[x][y][(size_z)-(1)], a[3][it][x][y][(size_z)-(1)], b[3][it][x][y][(size_z)-(1)], c[3][it][x][y][(size_z)-(1)], f[3][it][x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)], alfa_beta_beg6[3][it][i][x][y][size_z]);
		calccoef_pr_z(
			// int cntstep[3][x][y][(size_z)-(1)]
			self.wait(self.id(2)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).get_int(), 
			// int i
			self.arg(3).get_int(), 
			// value params[x][y][(size_z)-(1)]
			self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// value a[3][it][x][y][(size_z)-(1)]
			self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// value b[3][it][x][y][(size_z)-(1)]
			self.wait(self.id(1)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// value c[3][it][x][y][(size_z)-(1)]
			self.wait(self.id(7)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// value f[3][it][x][y][(size_z)-(1)]
			self.wait(self.id(3)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// name alfa[3][it][i][x][y][(size_z)-(1)]
			_out_0, 
			// name beta[3][it][i][x][y][(size_z)-(1)]
			_out_1, 
			// value alfa_beta_beg6[3][it][i][x][y][(size_z)-(1)]
			self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// name alfa_beta_beg6[3][it][i][x][y][size_z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][(self.wait(self.id(0))).get_int()], stored);
		}
	}

	self.destroy(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	self.destroy(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][(self.wait(self.id(0))).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+((self.wait(self.id(0))).get_int())))/(16))));
	// req_unlimited: alfa[3][it][i][x][y][(size_z)-(1)]
	{		DF posted=self.wait(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]);
	self.post(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))), -1);
	}
	// req_unlimited: beta[3][it][i][x][y][(size_z)-(1)]
	{		DF posted=self.wait(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]);
	self.post(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[3][it][i][x][y][size_z]
	{		DF posted=self.wait(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][(self.wait(self.id(0))).get_int()]);
	self.post(self.id(4)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][(self.wait(self.id(0))).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+((self.wait(self.id(0))).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_281(CF &self)
{
	// request_preliminary size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=282;
	return CONTINUE;
}

// RequestPreliminary : cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_282(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=283;
	return CONTINUE;
}

// After requests: cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_283(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+((self.wait(self.id(0))).get_int())))-(1)))/(16))))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));
	// request size_y
	self.request(self.id(1), CyclicLocator(0));
	// request size_x
	self.request(self.id(2), CyclicLocator(0));

	self.NextBlock=284;
	return CONTINUE;
}

// Request : cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_284(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=285;
	return CONTINUE;
}

// After requests: cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_285(CF &self)
{
	// request ubeg[3][it][x][y][(size_z)-(1)]
	self.request(self.id(3)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request params[x][y][(size_z)-(1)]
	self.request(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request cntstep[3][x][y][(size_z)-(1)]
	self.request(self.id(5)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request beta[3][it][i][x][y][(size_z)-(1)]
	self.request(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// request alfa[3][it][i][x][y][(size_z)-(1)]
	self.request(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));

	self.NextBlock=286;
	return CONTINUE;
}

// Request : cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_286(CF &self)
{
	// wait ubeg[3][it][x][y][(size_z)-(1)]
	if (self.wait(self.id(3)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][(size_z)-(1)]
	if (self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[3][x][y][(size_z)-(1)]
	if (self.wait(self.id(5)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait beta[3][it][i][x][y][(size_z)-(1)]
	if (self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait alfa[3][it][i][x][y][(size_z)-(1)]
	if (self.wait(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=287;
	return CONTINUE;
}

// After requests: cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
BlockRetStatus block_287(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_z[i][x][y][(size_z)-(1)]: calcVal((((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x), 3, cntstep[3][x][y][(size_z)-(1)], params[x][y][(size_z)-(1)], alfa[3][it][i][x][y][(size_z)-(1)], beta[3][it][i][x][y][(size_z)-(1)], u_cur[3][it][i][x][y][(size_z)-(1)], ubeg6[3][it][i][x][y][(size_z)-(2)], ubeg[3][it][x][y][(size_z)-(1)]);
		calcVal(
			// int (((((size_z)-(1))*(size_y))*(size_z))+((y)*(size_x)))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*((self.wait(self.id(1))).get_int())))*((self.wait(self.id(0))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(2))).get_int())))))+(self.arg(0).get_int())), 
			// int 3
			3, 
			// int cntstep[3][x][y][(size_z)-(1)]
			self.wait(self.id(5)[3][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]).get_int(), 
			// value params[x][y][(size_z)-(1)]
			self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// value alfa[3][it][i][x][y][(size_z)-(1)]
			self.wait(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// value beta[3][it][i][x][y][(size_z)-(1)]
			self.wait(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]), 
			// name u_cur[3][it][i][x][y][(size_z)-(1)]
			_out_0, 
			// name ubeg6[3][it][i][x][y][(size_z)-(2)]
			_out_1, 
			// value ubeg[3][it][x][y][(size_z)-(1)]
			self.wait(self.id(3)[3][self.arg(2).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))], stored);
		}
	}

	self.destroy(self.id(7)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	self.destroy(self.id(6)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))))/(16))));
	// req_unlimited: u_cur[3][it][i][x][y][(size_z)-(1)]
	{		DF posted=self.wait(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))]);
	self.post(self.id(8)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[3][it][i][x][y][(size_z)-(2)]
	{		DF posted=self.wait(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))]);
	self.post(self.id(9)[3][self.arg(2).get_int()][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(2))], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(static_cast<int>(((self.wait(self.id(0))).get_int())-(2)))))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_288(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=289;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_289(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=290;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_290(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(291);
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
BlockRetStatus block_291(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=292;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_292(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=293;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_293(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(294);
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
BlockRetStatus block_294(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=295;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_295(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=296;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_296(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf _l324: reduce_u(cntfor[3][x][y][z], x, y, z, u_cur[3][it], u[3][it][x][y][z]);
		CF *child=self.fork(297);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_z;
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
	}

	{ // FORK_BI: cf fill_u_z[x][y][z]: fill_u(3, cntstep[3][x][y][z], params[x][y][z], u[3][it][x][y][z], u_c[4][it][x][y][z]);
		CF *child=self.fork(300);
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

// BI_EXEC: cf _l324: reduce_u(cntfor[3][x][y][z], x, y, z, u_cur[3][it], u[3][it][x][y][z]);
BlockRetStatus block_297(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntfor[3][x][y][z]
	self.request(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=298;
	return CONTINUE;
}

// Request : cf _l324: reduce_u(cntfor[3][x][y][z], x, y, z, u_cur[3][it], u[3][it][x][y][z]);
BlockRetStatus block_298(CF &self)
{
	// wait cntfor[3][x][y][z]
	if (self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=299;
	return CONTINUE;
}

// After requests: cf _l324: reduce_u(cntfor[3][x][y][z], x, y, z, u_cur[3][it], u[3][it][x][y][z]);
BlockRetStatus block_299(CF &self)
{
	{ // EXEC_STRUCT: cf _l324: reduce_u(cntfor[3][x][y][z], x, y, z, u_cur[3][it], u[3][it][x][y][z]);
		CF *child=self.fork(121);
		child->arg(0)=self.wait(self.id(0)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int();
		child->arg(1)=self.arg(0).get_int();
		child->arg(2)=self.arg(1).get_int();
		child->arg(3)=self.arg(2).get_int();
		child->id(0)=self.id(1)[3][self.arg(3).get_int()];
		child->id(1)=self.id(2)[3][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()];
	}

	return EXIT;
}

// BI_EXEC: cf fill_u_z[x][y][z]: fill_u(3, cntstep[3][x][y][z], params[x][y][z], u[3][it][x][y][z], u_c[4][it][x][y][z]);