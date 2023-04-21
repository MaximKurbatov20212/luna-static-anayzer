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

// MAIN
BlockRetStatus block_0(CF &self)
{
self.arg(0)=self.argv(TYPE_STRING, 0);

	self.NextBlock=1;
	return CONTINUE;
}

// STRUCT: sub main(string arg1)
BlockRetStatus block_1(CF &self)
{
	Id _id_0=self.create_id(); // size_x
	Id _id_1=self.create_id(); // size_y
	Id _id_2=self.create_id(); // size_z
	Id _id_3=self.create_id(); // size
	Id _id_4=self.create_id(); // params
	Id _id_5=self.create_id(); // rank_x
	Id _id_6=self.create_id(); // rank_y
	Id _id_7=self.create_id(); // rank_z
	Id _id_8=self.create_id(); // dim_x
	Id _id_9=self.create_id(); // dim_y
	Id _id_10=self.create_id(); // dim_z
	Id _id_11=self.create_id(); // u_c
	Id _id_12=self.create_id(); // cntfor
	Id _id_13=self.create_id(); // cntstep
	Id _id_14=self.create_id(); // T
	Id _id_15=self.create_id(); // tprint
	Id _id_16=self.create_id(); // tau
	Id _id_17=self.create_id(); // curT
	Id _id_18=self.create_id(); // ubeg
	Id _id_19=self.create_id(); // iter

// GEN BODY: sub main(string arg1)
	{ // FORK_BI: cf _l82: getFG_Size(arg1, size_x, size_y, size_z, size);
		CF *child=self.fork(2);
		child->arg(0)=self.arg(0).get_string();
		child->id(0)=_id_0;
		child->id(1)=_id_1;
		child->id(2)=_id_2;
		child->id(3)=_id_3;
	}

	{ // FORK_BI: for i=0..(size_x)-(1);
		CF *child=self.fork(3);
		child->id(0)=_id_0;
		child->id(1)=_id_1;
		child->id(2)=_id_2;
		child->id(3)=_id_3;
		child->id(4)=_id_4;
		child->id(5)=_id_5;
		child->id(6)=_id_6;
		child->id(7)=_id_7;
		child->id(8)=_id_8;
		child->id(9)=_id_9;
		child->id(10)=_id_10;
		child->id(11)=_id_11;
		child->id(12)=_id_12;
		child->id(13)=_id_13;
	}

	{ // FORK_BI: cf _l98: initConst(params[0][0][0], T, tprint, tau);
		CF *child=self.fork(24);
		child->id(0)=_id_4;
		child->id(1)=_id_14;
		child->id(2)=_id_15;
		child->id(3)=_id_16;
	}

	{ // FORK_BI: cf _l99: rinit(0.000000, curT[0]);
		CF *child=self.fork(27);
		child->id(0)=_id_17;
	}

	{ // FORK_BI: while real((curT[(it)-(1)])<(T)), it=1..out iter;
		CF *child=self.fork(28);
		child->arg(0); // uninitialized
		child->id(0)=_id_17;
		child->id(1)=_id_14;
		child->id(2)=_id_16;
		child->id(3)=_id_1;
		child->id(4)=_id_2;
		child->id(5)=_id_13;
		child->id(6)=_id_0;
		child->id(7)=_id_4;
		child->id(8)=_id_11;
		child->id(9)=_id_18;
		child->id(10)=_id_12;
		child->id(11)=_id_19;
	}

	return EXIT;
}

// BI_EXEC: cf _l82: getFG_Size(arg1, size_x, size_y, size_z, size);
BlockRetStatus block_2(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		DF _out_3;
		// EXEC_EXTERN cf _l82: getFG_Size(arg1, size_x, size_y, size_z, size);
		getFG_Size(
			// string arg1
			(self.arg(0).get_string()).c_str(), 
			// name size_x
			_out_0, 
			// name size_y
			_out_1, 
			// name size_z
			_out_2, 
			// name size
			_out_3);

		{
			DF stored=_out_0;
			self.store(self.id(0), stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(1), stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(2), stored);
		}
		{
			DF stored=_out_3;
			self.store(self.id(3), stored);
		}
	}

	// req_unlimited: size_x
	{		DF posted=self.wait(self.id(0));
	self.post(self.id(0), posted, CyclicLocator(0), -1);
	}
	// req_unlimited: size_y
	{		DF posted=self.wait(self.id(1));
	self.post(self.id(1), posted, CyclicLocator(0), -1);
	}
	// req_unlimited: size_z
	{		DF posted=self.wait(self.id(2));
	self.post(self.id(2), posted, CyclicLocator(0), -1);
	}
	// req_unlimited: size
	{		DF posted=self.wait(self.id(3));
	self.post(self.id(3), posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_FOR: for i = 0 .. (size_x)-(1)
BlockRetStatus block_3(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=4;
	return CONTINUE;
}

// Request : for i = 0 .. (size_x)-(1)
BlockRetStatus block_4(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=5;
	return CONTINUE;
}

// After requests: for i = 0 .. (size_x)-(1)
BlockRetStatus block_5(CF &self)
{
	for (int _lc_i=0; _lc_i<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_i++) {

// GEN BODY: for i = 0 .. (size_x)-(1)
	{ // FORK_BI: for j=0..(size_y)-(1);
		CF *child=self.fork(6);
		child->arg(0)=_lc_i;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(0);
		child->id(3)=self.id(3);
		child->id(4)=self.id(4);
		child->id(5)=self.id(5);
		child->id(6)=self.id(6);
		child->id(7)=self.id(7);
		child->id(8)=self.id(8);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
	}

	} // for
	return EXIT;
}

// BI_FOR: for j = 0 .. (size_y)-(1)
BlockRetStatus block_6(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=7;
	return CONTINUE;
}

// Request : for j = 0 .. (size_y)-(1)
BlockRetStatus block_7(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=8;
	return CONTINUE;
}

// After requests: for j = 0 .. (size_y)-(1)
BlockRetStatus block_8(CF &self)
{
	for (int _lc_j=0; _lc_j<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_j++) {

// GEN BODY: for j = 0 .. (size_y)-(1)
	{ // FORK_BI: for k=0..(size_z)-(1);
		CF *child=self.fork(9);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_j;
		child->id(0)=self.id(1);
		child->id(1)=self.id(0);
		child->id(2)=self.id(2);
		child->id(3)=self.id(3);
		child->id(4)=self.id(4);
		child->id(5)=self.id(5);
		child->id(6)=self.id(6);
		child->id(7)=self.id(7);
		child->id(8)=self.id(8);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
	}

	} // for
	return EXIT;
}

// BI_FOR: for k = 0 .. (size_z)-(1)
BlockRetStatus block_9(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=10;
	return CONTINUE;
}

// Request : for k = 0 .. (size_z)-(1)
BlockRetStatus block_10(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=11;
	return CONTINUE;
}

// After requests: for k = 0 .. (size_z)-(1)
BlockRetStatus block_11(CF &self)
{
	for (int _lc_k=0; _lc_k<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_k++) {

// GEN BODY: for k = 0 .. (size_z)-(1)
	{ // FORK_BI: cf loadData[i][j][k]: loadData(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), size, params[i][j][k], rank_x[i][j][k], rank_y[i][j][k], rank_z[i][j][k], dim_x[i][j][k], dim_y[i][j][k], dim_z[i][j][k], u_c[1][1][i][j][k]);
		CF *child=self.fork(12);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_k;
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

	{ // FORK_BI: cf initpar_x[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 1, params[i][j][k], cntfor[1][i][j][k], cntstep[1][i][j][k]);
		CF *child=self.fork(15);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_k;
		child->id(0)=self.id(4);
		child->id(1)=self.id(1);
		child->id(2)=self.id(2);
		child->id(3)=self.id(12);
		child->id(4)=self.id(13);
	}

	{ // FORK_BI: cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 2, params[i][j][k], cntfor[2][i][j][k], cntstep[2][i][j][k]);
		CF *child=self.fork(18);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_k;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(4);
		child->id(3)=self.id(12);
		child->id(4)=self.id(13);
	}

	{ // FORK_BI: cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 3, params[i][j][k], cntfor[3][i][j][k], cntstep[3][i][j][k]);
		CF *child=self.fork(21);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=_lc_k;
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(4);
		child->id(3)=self.id(12);
		child->id(4)=self.id(13);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf loadData[i][j][k]: loadData(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), size, params[i][j][k], rank_x[i][j][k], rank_y[i][j][k], rank_z[i][j][k], dim_x[i][j][k], dim_y[i][j][k], dim_z[i][j][k], u_c[1][1][i][j][k]);
BlockRetStatus block_12(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));
	// request size_x
	self.request(self.id(1), CyclicLocator(0));
	// request size
	self.request(self.id(2), CyclicLocator(0));

	self.NextBlock=13;
	return CONTINUE;
}

// Request : cf loadData[i][j][k]: loadData(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), size, params[i][j][k], rank_x[i][j][k], rank_y[i][j][k], rank_z[i][j][k], dim_x[i][j][k], dim_y[i][j][k], dim_z[i][j][k], u_c[1][1][i][j][k]);
BlockRetStatus block_13(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait size
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=14;
	return CONTINUE;
}

// After requests: cf loadData[i][j][k]: loadData(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), size, params[i][j][k], rank_x[i][j][k], rank_y[i][j][k], rank_z[i][j][k], dim_x[i][j][k], dim_y[i][j][k], dim_z[i][j][k], u_c[1][1][i][j][k]);
BlockRetStatus block_14(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		DF _out_3;
		DF _out_4;
		DF _out_5;
		DF _out_6;
		DF _out_7;
		// EXEC_EXTERN cf loadData[i][j][k]: loadData(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), size, params[i][j][k], rank_x[i][j][k], rank_y[i][j][k], rank_z[i][j][k], dim_x[i][j][k], dim_y[i][j][k], dim_z[i][j][k], u_c[1][1][i][j][k]);
		loadData(
			// int ((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(0))).get_int())))*((self.wait(self.id(1))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(1))).get_int())))))+(self.arg(0).get_int())), 
			// int size
			(self.wait(self.id(2))).get_int(), 
			// name params[i][j][k]
			_out_0, 
			// name rank_x[i][j][k]
			_out_1, 
			// name rank_y[i][j][k]
			_out_2, 
			// name rank_z[i][j][k]
			_out_3, 
			// name dim_x[i][j][k]
			_out_4, 
			// name dim_y[i][j][k]
			_out_5, 
			// name dim_z[i][j][k]
			_out_6, 
			// name u_c[1][1][i][j][k]
			_out_7);

		{
			DF stored=_out_0;
			self.store(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_3;
			self.store(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_4;
			self.store(self.id(7)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_5;
			self.store(self.id(8)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_6;
			self.store(self.id(9)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_7;
			self.store(self.id(10)[1][1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: params[i][j][k]
	{		DF posted=self.wait(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: rank_x[i][j][k]
	{		DF posted=self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: rank_y[i][j][k]
	{		DF posted=self.wait(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(5)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: rank_z[i][j][k]
	{		DF posted=self.wait(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(6)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: dim_x[i][j][k]
	{		DF posted=self.wait(self.id(7)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(7)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: dim_y[i][j][k]
	{		DF posted=self.wait(self.id(8)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(8)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: dim_z[i][j][k]
	{		DF posted=self.wait(self.id(9)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(9)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: u_c[1][1][i][j][k]
	{		DF posted=self.wait(self.id(10)[1][1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(10)[1][1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf initpar_x[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 1, params[i][j][k], cntfor[1][i][j][k], cntstep[1][i][j][k]);
BlockRetStatus block_15(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request params[i][j][k]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_y
	self.request(self.id(1), CyclicLocator(0));
	// request size_x
	self.request(self.id(2), CyclicLocator(0));

	self.NextBlock=16;
	return CONTINUE;
}

// Request : cf initpar_x[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 1, params[i][j][k], cntfor[1][i][j][k], cntstep[1][i][j][k]);
BlockRetStatus block_16(CF &self)
{
	// wait params[i][j][k]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
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


	self.NextBlock=17;
	return CONTINUE;
}

// After requests: cf initpar_x[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 1, params[i][j][k], cntfor[1][i][j][k], cntstep[1][i][j][k]);
BlockRetStatus block_17(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf initpar_x[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 1, params[i][j][k], cntfor[1][i][j][k], cntstep[1][i][j][k]);
		initforParams(
			// int ((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(1))).get_int())))*((self.wait(self.id(2))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(2))).get_int())))))+(self.arg(0).get_int())), 
			// int 1
			1, 
			// value params[i][j][k]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name cntfor[1][i][j][k]
			_out_0, 
			// name cntstep[1][i][j][k]
			_out_1);

		{
			DF stored=_out_0;
			self.store(self.id(3)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(4)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: cntfor[1][i][j][k]
	{		DF posted=self.wait(self.id(3)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: cntstep[1][i][j][k]
	{		DF posted=self.wait(self.id(4)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 2, params[i][j][k], cntfor[2][i][j][k], cntstep[2][i][j][k]);
BlockRetStatus block_18(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));
	// request size_x
	self.request(self.id(1), CyclicLocator(0));
	// request params[i][j][k]
	self.request(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=19;
	return CONTINUE;
}

// Request : cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 2, params[i][j][k], cntfor[2][i][j][k], cntstep[2][i][j][k]);
BlockRetStatus block_19(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait params[i][j][k]
	if (self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=20;
	return CONTINUE;
}

// After requests: cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 2, params[i][j][k], cntfor[2][i][j][k], cntstep[2][i][j][k]);
BlockRetStatus block_20(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 2, params[i][j][k], cntfor[2][i][j][k], cntstep[2][i][j][k]);
		initforParams(
			// int ((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(0))).get_int())))*((self.wait(self.id(1))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(1))).get_int())))))+(self.arg(0).get_int())), 
			// int 2
			2, 
			// value params[i][j][k]
			self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name cntfor[2][i][j][k]
			_out_0, 
			// name cntstep[2][i][j][k]
			_out_1);

		{
			DF stored=_out_0;
			self.store(self.id(3)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(4)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: cntfor[2][i][j][k]
	{		DF posted=self.wait(self.id(3)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: cntstep[2][i][j][k]
	{		DF posted=self.wait(self.id(4)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[2][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 3, params[i][j][k], cntfor[3][i][j][k], cntstep[3][i][j][k]);
BlockRetStatus block_21(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));
	// request size_x
	self.request(self.id(1), CyclicLocator(0));
	// request params[i][j][k]
	self.request(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=22;
	return CONTINUE;
}

// Request : cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 3, params[i][j][k], cntfor[3][i][j][k], cntstep[3][i][j][k]);
BlockRetStatus block_22(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait params[i][j][k]
	if (self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=23;
	return CONTINUE;
}

// After requests: cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 3, params[i][j][k], cntfor[3][i][j][k], cntstep[3][i][j][k]);
BlockRetStatus block_23(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf initpar_y[i][j][k]: initforParams(((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i), 3, params[i][j][k], cntfor[3][i][j][k], cntstep[3][i][j][k]);
		initforParams(
			// int ((((k)*(size_y))*(size_x))+((j)*(size_x)))+(i)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(0))).get_int())))*((self.wait(self.id(1))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(1))).get_int())))))+(self.arg(0).get_int())), 
			// int 3
			3, 
			// value params[i][j][k]
			self.wait(self.id(2)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name cntfor[3][i][j][k]
			_out_0, 
			// name cntstep[3][i][j][k]
			_out_1);

		{
			DF stored=_out_0;
			self.store(self.id(3)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(4)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: cntfor[3][i][j][k]
	{		DF posted=self.wait(self.id(3)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: cntstep[3][i][j][k]
	{		DF posted=self.wait(self.id(4)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[3][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l98: initConst(params[0][0][0], T, tprint, tau);
BlockRetStatus block_24(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request params[0][0][0]
	self.request(self.id(0)[0][0][0], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((0)*(2)))))+(0)))/(16))));

	self.NextBlock=25;
	return CONTINUE;
}

// Request : cf _l98: initConst(params[0][0][0], T, tprint, tau);
BlockRetStatus block_25(CF &self)
{
	// wait params[0][0][0]
	if (self.wait(self.id(0)[0][0][0]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=26;
	return CONTINUE;
}

// After requests: cf _l98: initConst(params[0][0][0], T, tprint, tau);
BlockRetStatus block_26(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf _l98: initConst(params[0][0][0], T, tprint, tau);
		initconst(
			// value params[0][0][0]
			self.wait(self.id(0)[0][0][0]), 
			// name T
			_out_0, 
			// name tprint
			_out_1, 
			// name tau
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(1), stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(2), stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(3), stored);
		}
	}

	// req_unlimited: T
	{		DF posted=self.wait(self.id(1));
	self.post(self.id(1), posted, CyclicLocator(0), -1);
	}
	// req_unlimited: tprint
	{		DF posted=self.wait(self.id(2));
	self.post(self.id(2), posted, CyclicLocator(0), -1);
	}
	// req_unlimited: tau
	{		DF posted=self.wait(self.id(3));
	self.post(self.id(3), posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_EXEC: cf _l99: rinit(0.000000, curT[0]);
BlockRetStatus block_27(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	{
		DF _out_0;
		// EXEC_EXTERN cf _l99: rinit(0.000000, curT[0]);
		c_rinit(
			// real 0.000000
			0.000000, 
			// name curT[0]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0)[0], stored);
		}
	}

	// req_unlimited: curT[0]
	{		DF posted=self.wait(self.id(0)[0]);
	self.post(self.id(0)[0], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_WHILE: init counter: while real((curT[(it)-(1)])<(T)), it = 1 .. out iter
BlockRetStatus block_28(CF &self)
{
	self.arg(0)=(1);
	self.NextBlock=29;
	return CONTINUE;
}

// WHILE: preparations: while real((curT[(it)-(1)])<(T)), it = 1 .. out iter
BlockRetStatus block_29(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request curT[(it)-(1)]
	self.request(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))], CyclicLocator(0));
	// request T
	self.request(self.id(1), CyclicLocator(0));

	self.NextBlock=30;
	return CONTINUE;
}

// Request : while real((curT[(it)-(1)])<(T)), it = 1 .. out iter
BlockRetStatus block_30(CF &self)
{
	// wait curT[(it)-(1)]
	if (self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait T
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=31;
	return CONTINUE;
}

// After requests: while real((curT[(it)-(1)])<(T)), it = 1 .. out iter
BlockRetStatus block_31(CF &self)
{
	if (0 != static_cast<int>(static_cast<double>(((self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))]))<(self.wait(self.id(1)))).get_int()))) {
	Id _id_0=self.create_id(); // alfa_beta_beg
	Id _id_1=self.create_id(); // a
	Id _id_2=self.create_id(); // b
	Id _id_3=self.create_id(); // c
	Id _id_4=self.create_id(); // f
	Id _id_5=self.create_id(); // alfa
	Id _id_6=self.create_id(); // beta
	Id _id_7=self.create_id(); // alfa_beta_beg6
	Id _id_8=self.create_id(); // ubeg6
	Id _id_9=self.create_id(); // u_cur
	Id _id_10=self.create_id(); // u
	Id _id_11=self.create_id(); // sendar_x_L
	Id _id_12=self.create_id(); // sendar_x_R
	Id _id_13=self.create_id(); // sendar_y_T
	Id _id_14=self.create_id(); // sendar_y_B
	Id _id_15=self.create_id(); // sendar_z_F
	Id _id_16=self.create_id(); // sendar_z_B

// GEN BODY: while real((curT[(it)-(1)])<(T)), it = 1 .. out iter
	{ // FORK_BI: cf _l106: rinit((curT[(it)-(1)])+(tau), curT[it]);
		CF *child=self.fork(32);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(0);
		child->id(1)=self.id(2);
	}

	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(35);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(3);
		child->id(1)=self.id(4);
		child->id(2)=self.id(5);
		child->id(3)=_id_0;
		child->id(4)=self.id(6);
		child->id(5)=self.id(7);
		child->id(6)=self.id(8);
		child->id(7)=_id_1;
		child->id(8)=_id_2;
		child->id(9)=_id_3;
		child->id(10)=_id_4;
		child->id(11)=self.id(9);
	}

	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(57);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(3);
		child->id(1)=self.id(4);
		child->id(2)=self.id(10);
		child->id(3)=self.id(6);
		child->id(4)=self.id(7);
		child->id(5)=_id_4;
		child->id(6)=_id_1;
		child->id(7)=_id_2;
		child->id(8)=self.id(5);
		child->id(9)=_id_0;
		child->id(10)=_id_3;
		child->id(11)=_id_5;
		child->id(12)=_id_6;
		child->id(13)=_id_7;
		child->id(14)=_id_8;
		child->id(15)=_id_9;
		child->id(16)=self.id(9);
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(109);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(4);
		child->id(3)=self.id(10);
		child->id(4)=_id_9;
		child->id(5)=_id_10;
		child->id(6)=self.id(7);
		child->id(7)=self.id(5);
		child->id(8)=self.id(8);
		child->id(9)=_id_1;
		child->id(10)=_id_2;
		child->id(11)=_id_3;
		child->id(12)=_id_4;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(125);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(4);
		child->id(2)=self.id(5);
		child->id(3)=_id_0;
		child->id(4)=self.id(3);
		child->id(5)=self.id(8);
		child->id(6)=self.id(7);
		child->id(7)=_id_1;
		child->id(8)=_id_2;
		child->id(9)=_id_3;
		child->id(10)=_id_4;
		child->id(11)=self.id(9);
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(147);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(4);
		child->id(2)=self.id(10);
		child->id(3)=_id_2;
		child->id(4)=self.id(5);
		child->id(5)=_id_4;
		child->id(6)=_id_1;
		child->id(7)=_id_3;
		child->id(8)=self.id(7);
		child->id(9)=_id_0;
		child->id(10)=_id_5;
		child->id(11)=_id_6;
		child->id(12)=_id_7;
		child->id(13)=self.id(3);
		child->id(14)=_id_8;
		child->id(15)=_id_9;
		child->id(16)=self.id(9);
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(199);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(4);
		child->id(3)=self.id(10);
		child->id(4)=_id_9;
		child->id(5)=_id_10;
		child->id(6)=self.id(5);
		child->id(7)=self.id(7);
		child->id(8)=self.id(8);
		child->id(9)=_id_1;
		child->id(10)=_id_2;
		child->id(11)=_id_3;
		child->id(12)=_id_4;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(214);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(5);
		child->id(3)=_id_0;
		child->id(4)=self.id(4);
		child->id(5)=self.id(8);
		child->id(6)=self.id(7);
		child->id(7)=_id_1;
		child->id(8)=_id_2;
		child->id(9)=_id_3;
		child->id(10)=_id_4;
		child->id(11)=self.id(9);
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(236);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(10);
		child->id(3)=_id_0;
		child->id(4)=self.id(5);
		child->id(5)=_id_1;
		child->id(6)=self.id(7);
		child->id(7)=_id_3;
		child->id(8)=_id_4;
		child->id(9)=_id_2;
		child->id(10)=_id_5;
		child->id(11)=_id_6;
		child->id(12)=_id_7;
		child->id(13)=self.id(4);
		child->id(14)=_id_8;
		child->id(15)=_id_9;
		child->id(16)=self.id(9);
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(288);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(4);
		child->id(3)=self.id(10);
		child->id(4)=_id_9;
		child->id(5)=_id_10;
		child->id(6)=self.id(5);
		child->id(7)=self.id(7);
		child->id(8)=self.id(8);
		child->id(9)=_id_1;
		child->id(10)=_id_2;
		child->id(11)=_id_3;
		child->id(12)=_id_4;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(303);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(4);
		child->id(3)=self.id(8);
		child->id(4)=self.id(7);
		child->id(5)=_id_11;
		child->id(6)=_id_12;
		child->id(7)=_id_13;
		child->id(8)=_id_14;
		child->id(9)=_id_15;
		child->id(10)=_id_16;
	}

	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(321);
		child->id(0)=self.id(3);
		child->id(1)=self.id(4);
		child->id(2)=_id_12;
	}

	{ // FORK_BI: for y=0..(size_y)-(1);
		CF *child=self.fork(328);
		child->id(0)=self.id(3);
		child->id(1)=self.id(4);
		child->id(2)=self.id(6);
		child->id(3)=_id_11;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(339);
		child->id(0)=self.id(6);
		child->id(1)=self.id(4);
		child->id(2)=_id_13;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(346);
		child->id(0)=self.id(6);
		child->id(1)=self.id(4);
		child->id(2)=self.id(3);
		child->id(3)=_id_14;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(357);
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=_id_15;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(364);
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(4);
		child->id(3)=_id_16;
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(375);
		child->arg(0)=self.arg(0).get_int();
		child->id(0)=self.id(6);
		child->id(1)=self.id(3);
		child->id(2)=self.id(4);
		child->id(3)=_id_16;
		child->id(4)=_id_13;
		child->id(5)=_id_15;
		child->id(6)=self.id(8);
		child->id(7)=_id_12;
		child->id(8)=_id_11;
		child->id(9)=_id_14;
		child->id(10)=self.id(7);
	}

	self.arg(0)=(self.arg(0).get_int())+1;
	self.NextBlock=29;
	return CONTINUE; // next while iter
	} else { // while
		self.store(self.id(11), self.arg(0)); // set wout
	// req_unlimited: iter
	{		DF posted=self.wait(self.id(11));
	self.post(self.id(11), posted, CyclicLocator(0), -1);
	}
	} // while
	return EXIT;
}

// BI_EXEC: cf _l106: rinit((curT[(it)-(1)])+(tau), curT[it]);
BlockRetStatus block_32(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request curT[(it)-(1)]
	self.request(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))], CyclicLocator(0));
	// request tau
	self.request(self.id(1), CyclicLocator(0));

	self.NextBlock=33;
	return CONTINUE;
}

// Request : cf _l106: rinit((curT[(it)-(1)])+(tau), curT[it]);
BlockRetStatus block_33(CF &self)
{
	// wait curT[(it)-(1)]
	if (self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))]).is_unset()) {
		return WAIT;
	}

	// wait tau
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=34;
	return CONTINUE;
}

// After requests: cf _l106: rinit((curT[(it)-(1)])+(tau), curT[it]);
BlockRetStatus block_34(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf _l106: rinit((curT[(it)-(1)])+(tau), curT[it]);
		c_rinit(
			// real (curT[(it)-(1)])+(tau)
			static_cast<double>(((self.wait(self.id(0)[static_cast<int>((self.arg(0).get_int())-(1))]))+(self.wait(self.id(1)))).get_real()), 
			// name curT[it]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(0)[self.arg(0).get_int()], stored);
		}
	}

	// req_unlimited: curT[it]
	{		DF posted=self.wait(self.id(0)[self.arg(0).get_int()]);
	self.post(self.id(0)[self.arg(0).get_int()], posted, CyclicLocator(0), -1);
	}
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_35(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=36;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_36(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=37;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_37(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(38);
		child->arg(0)=_lc_y;
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
BlockRetStatus block_38(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=39;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_39(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=40;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_40(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: cf init_alfa_beta_x[0][y][z]: init_alfa_beta(cntstep[1][0][y][z], alfa_beta_beg[1][it][0][y][z]);
		CF *child=self.fork(41);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
	}

	{ // FORK_BI: for x=0..(size_x)-(1);
		CF *child=self.fork(44);
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

	{ // FORK_BI: cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
		CF *child=self.fork(50);
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

// BI_EXEC: cf init_alfa_beta_x[0][y][z]: init_alfa_beta(cntstep[1][0][y][z], alfa_beta_beg[1][it][0][y][z]);
BlockRetStatus block_41(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[1][0][y][z]
	self.request(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=42;
	return CONTINUE;
}

// Request : cf init_alfa_beta_x[0][y][z]: init_alfa_beta(cntstep[1][0][y][z], alfa_beta_beg[1][it][0][y][z]);
BlockRetStatus block_42(CF &self)
{
	// wait cntstep[1][0][y][z]
	if (self.wait(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=43;
	return CONTINUE;
}

// After requests: cf init_alfa_beta_x[0][y][z]: init_alfa_beta(cntstep[1][0][y][z], alfa_beta_beg[1][it][0][y][z]);
BlockRetStatus block_43(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf init_alfa_beta_x[0][y][z]: init_alfa_beta(cntstep[1][0][y][z], alfa_beta_beg[1][it][0][y][z]);
		init_alfa_beta(
			// int cntstep[1][0][y][z]
			self.wait(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).get_int(), 
			// name alfa_beta_beg[1][it][0][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(1)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: alfa_beta_beg[1][it][0][y][z]
	{		DF posted=self.wait(self.id(1)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(1)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 0 .. (size_x)-(1)
BlockRetStatus block_44(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=45;
	return CONTINUE;
}

// Request : for x = 0 .. (size_x)-(1)
BlockRetStatus block_45(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=46;
	return CONTINUE;
}

// After requests: for x = 0 .. (size_x)-(1)
BlockRetStatus block_46(CF &self)
{
	for (int _lc_x=0; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_x++) {

// GEN BODY: for x = 0 .. (size_x)-(1)
	{ // FORK_BI: cf calcCoef_x[x][y][z]: calcCoef_x(params[x][y][z], u_c[1][it][x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z]);
		CF *child=self.fork(47);
		child->arg(0)=_lc_x;
		child->arg(1)=self.arg(0).get_int();
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

// BI_EXEC: cf calcCoef_x[x][y][z]: calcCoef_x(params[x][y][z], u_c[1][it][x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z]);
BlockRetStatus block_47(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request params[x][y][z]
	self.request(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request u_c[1][it][x][y][z]
	self.request(self.id(1)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=48;
	return CONTINUE;
}

// Request : cf calcCoef_x[x][y][z]: calcCoef_x(params[x][y][z], u_c[1][it][x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z]);
BlockRetStatus block_48(CF &self)
{
	// wait params[x][y][z]
	if (self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait u_c[1][it][x][y][z]
	if (self.wait(self.id(1)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=49;
	return CONTINUE;
}

// After requests: cf calcCoef_x[x][y][z]: calcCoef_x(params[x][y][z], u_c[1][it][x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z]);
BlockRetStatus block_49(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		DF _out_3;
		// EXEC_EXTERN cf calcCoef_x[x][y][z]: calcCoef_x(params[x][y][z], u_c[1][it][x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z]);
		calcCoef_x(
			// value params[x][y][z]
			self.wait(self.id(0)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value u_c[1][it][x][y][z]
			self.wait(self.id(1)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name a[1][it][x][y][z]
			_out_0, 
			// name b[1][it][x][y][z]
			_out_1, 
			// name c[1][it][x][y][z]
			_out_2, 
			// name f[1][it][x][y][z]
			_out_3);

		{
			DF stored=_out_0;
			self.store(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(4)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_3;
			self.store(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	// req_unlimited: a[1][it][x][y][z]
	{		DF posted=self.wait(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(2)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: b[1][it][x][y][z]
	{		DF posted=self.wait(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: c[1][it][x][y][z]
	{		DF posted=self.wait(self.id(4)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(4)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: f[1][it][x][y][z]
	{		DF posted=self.wait(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_50(CF &self)
{
	// request_preliminary size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=51;
	return CONTINUE;
}

// RequestPreliminary : cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_51(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=52;
	return CONTINUE;
}

// After requests: cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_52(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=53;
	return CONTINUE;
}

// Request : cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_53(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=54;
	return CONTINUE;
}

// After requests: cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_54(CF &self)
{
	// request cntstep[1][(size_x)-(1)][y][z]
	self.request(self.id(1)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=55;
	return CONTINUE;
}

// Request : cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_55(CF &self)
{
	// wait cntstep[1][(size_x)-(1)][y][z]
	if (self.wait(self.id(1)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=56;
	return CONTINUE;
}

// After requests: cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
BlockRetStatus block_56(CF &self)
{
	{
		DF _out_0;
		// EXEC_EXTERN cf init_uend_x[(size_x)-(1)][y][z]: init_uend(cntstep[1][(size_x)-(1)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
		init_uend(
			// int cntstep[1][(size_x)-(1)][y][z]
			self.wait(self.id(1)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).get_int(), 
			// name ubeg[1][it][(size_x)-(1)][y][z]
			_out_0);

		{
			DF stored=_out_0;
			self.store(self.id(2)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: ubeg[1][it][(size_x)-(1)][y][z]
	{		DF posted=self.wait(self.id(2)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(2)[1][self.arg(2).get_int()][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for y = 0 .. (size_y)-(1)
BlockRetStatus block_57(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_y
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=58;
	return CONTINUE;
}

// Request : for y = 0 .. (size_y)-(1)
BlockRetStatus block_58(CF &self)
{
	// wait size_y
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=59;
	return CONTINUE;
}

// After requests: for y = 0 .. (size_y)-(1)
BlockRetStatus block_59(CF &self)
{
	for (int _lc_y=0; _lc_y<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_y++) {

// GEN BODY: for y = 0 .. (size_y)-(1)
	{ // FORK_BI: for z=0..(size_z)-(1);
		CF *child=self.fork(60);
		child->arg(0)=_lc_y;
		child->arg(1)=self.arg(0).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(3);
		child->id(3)=self.id(4);
		child->id(4)=self.id(5);
		child->id(5)=self.id(6);
		child->id(6)=self.id(7);
		child->id(7)=self.id(0);
		child->id(8)=self.id(8);
		child->id(9)=self.id(9);
		child->id(10)=self.id(10);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
		child->id(15)=self.id(15);
		child->id(16)=self.id(16);
	}

	} // for
	return EXIT;
}

// BI_FOR: for z = 0 .. (size_z)-(1)
BlockRetStatus block_60(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=61;
	return CONTINUE;
}

// Request : for z = 0 .. (size_z)-(1)
BlockRetStatus block_61(CF &self)
{
	// wait size_z
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=62;
	return CONTINUE;
}

// After requests: for z = 0 .. (size_z)-(1)
BlockRetStatus block_62(CF &self)
{
	for (int _lc_z=0; _lc_z<=static_cast<int>(((self.wait(self.id(0))).get_int())-(1)); _lc_z++) {

// GEN BODY: for z = 0 .. (size_z)-(1)
	{ // FORK_BI: for j=0..(cntfor[1][0][y][z])-(1);
		CF *child=self.fork(63);
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
		child->id(10)=self.id(0);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
		child->id(15)=self.id(15);
	}

	{ // FORK_BI: for x=1..(size_x)-(2);
		CF *child=self.fork(75);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(2);
		child->id(1)=self.id(1);
		child->id(2)=self.id(13);
		child->id(3)=self.id(10);
		child->id(4)=self.id(7);
		child->id(5)=self.id(5);
		child->id(6)=self.id(3);
		child->id(7)=self.id(4);
		child->id(8)=self.id(0);
		child->id(9)=self.id(6);
		child->id(10)=self.id(8);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(14);
		child->id(14)=self.id(15);
	}

	{ // FORK_BI: for j=0..(cntfor[1][(size_x)-(1)][y][z])-(1);
		CF *child=self.fork(87);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=_lc_z;
		child->arg(2)=self.arg(1).get_int();
		child->id(0)=self.id(2);
		child->id(1)=self.id(1);
		child->id(2)=self.id(0);
		child->id(3)=self.id(7);
		child->id(4)=self.id(5);
		child->id(5)=self.id(8);
		child->id(6)=self.id(10);
		child->id(7)=self.id(6);
		child->id(8)=self.id(4);
		child->id(9)=self.id(13);
		child->id(10)=self.id(3);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(16);
		child->id(14)=self.id(15);
		child->id(15)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_FOR: for j = 0 .. (cntfor[1][0][y][z])-(1)
BlockRetStatus block_63(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[1][0][y][z]
	self.request(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(0));

	self.NextBlock=64;
	return CONTINUE;
}

// Request : for j = 0 .. (cntfor[1][0][y][z])-(1)
BlockRetStatus block_64(CF &self)
{
	// wait cntfor[1][0][y][z]
	if (self.wait(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=65;
	return CONTINUE;
}

// After requests: for j = 0 .. (cntfor[1][0][y][z])-(1)
BlockRetStatus block_65(CF &self)
{
	for (int _lc_j=0; _lc_j<=static_cast<int>((self.wait(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).get_int())-(1)); _lc_j++) {

// GEN BODY: for j = 0 .. (cntfor[1][0][y][z])-(1)
	{ // FORK_BI: cf calccoef_pr_x[j][0][y][z]: calccoef_pr_x((((z)*(size_y))*(size_z))+((y)*(size_x)), cntstep[1][0][y][z], j, params[0][y][z], a[1][it][0][y][z], b[1][it][0][y][z], c[1][it][0][y][z], f[1][it][0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], alfa_beta_beg[1][it][0][y][z], alfa_beta_beg6[1][it][j][1][y][z]);
		CF *child=self.fork(66);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_j;
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
	}

	{ // FORK_BI: if (size_x)>(1)
		CF *child=self.fork(69);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_j;
		child->id(0)=self.id(1);
		child->id(1)=self.id(7);
		child->id(2)=self.id(14);
		child->id(3)=self.id(11);
		child->id(4)=self.id(6);
		child->id(5)=self.id(2);
		child->id(6)=self.id(10);
		child->id(7)=self.id(12);
		child->id(8)=self.id(15);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_x[j][0][y][z]: calccoef_pr_x((((z)*(size_y))*(size_z))+((y)*(size_x)), cntstep[1][0][y][z], j, params[0][y][z], a[1][it][0][y][z], b[1][it][0][y][z], c[1][it][0][y][z], f[1][it][0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], alfa_beta_beg[1][it][0][y][z], alfa_beta_beg6[1][it][j][1][y][z]);
BlockRetStatus block_66(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));
	// request params[0][y][z]
	self.request(self.id(1)[0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request f[1][it][0][y][z]
	self.request(self.id(2)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request a[1][it][0][y][z]
	self.request(self.id(3)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request b[1][it][0][y][z]
	self.request(self.id(4)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_y
	self.request(self.id(5), CyclicLocator(0));
	// request cntstep[1][0][y][z]
	self.request(self.id(6)[1][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request alfa_beta_beg[1][it][0][y][z]
	self.request(self.id(7)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request c[1][it][0][y][z]
	self.request(self.id(8)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_z
	self.request(self.id(9), CyclicLocator(0));

	self.NextBlock=67;
	return CONTINUE;
}

// Request : cf calccoef_pr_x[j][0][y][z]: calccoef_pr_x((((z)*(size_y))*(size_z))+((y)*(size_x)), cntstep[1][0][y][z], j, params[0][y][z], a[1][it][0][y][z], b[1][it][0][y][z], c[1][it][0][y][z], f[1][it][0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], alfa_beta_beg[1][it][0][y][z], alfa_beta_beg6[1][it][j][1][y][z]);
BlockRetStatus block_67(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait params[0][y][z]
	if (self.wait(self.id(1)[0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[1][it][0][y][z]
	if (self.wait(self.id(2)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait a[1][it][0][y][z]
	if (self.wait(self.id(3)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait b[1][it][0][y][z]
	if (self.wait(self.id(4)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(5)).is_unset()) {
		return WAIT;
	}

	// wait cntstep[1][0][y][z]
	if (self.wait(self.id(6)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait alfa_beta_beg[1][it][0][y][z]
	if (self.wait(self.id(7)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[1][it][0][y][z]
	if (self.wait(self.id(8)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(9)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=68;
	return CONTINUE;
}

// After requests: cf calccoef_pr_x[j][0][y][z]: calccoef_pr_x((((z)*(size_y))*(size_z))+((y)*(size_x)), cntstep[1][0][y][z], j, params[0][y][z], a[1][it][0][y][z], b[1][it][0][y][z], c[1][it][0][y][z], f[1][it][0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], alfa_beta_beg[1][it][0][y][z], alfa_beta_beg6[1][it][j][1][y][z]);
BlockRetStatus block_68(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_x[j][0][y][z]: calccoef_pr_x((((z)*(size_y))*(size_z))+((y)*(size_x)), cntstep[1][0][y][z], j, params[0][y][z], a[1][it][0][y][z], b[1][it][0][y][z], c[1][it][0][y][z], f[1][it][0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], alfa_beta_beg[1][it][0][y][z], alfa_beta_beg6[1][it][j][1][y][z]);
		calccoef_pr_x(
			// int (((z)*(size_y))*(size_z))+((y)*(size_x))
			static_cast<int>((static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(5))).get_int())))*((self.wait(self.id(9))).get_int())))+(static_cast<int>((self.arg(0).get_int())*((self.wait(self.id(0))).get_int())))), 
			// int cntstep[1][0][y][z]
			self.wait(self.id(6)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).get_int(), 
			// int j
			self.arg(3).get_int(), 
			// value params[0][y][z]
			self.wait(self.id(1)[0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value a[1][it][0][y][z]
			self.wait(self.id(3)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value b[1][it][0][y][z]
			self.wait(self.id(4)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value c[1][it][0][y][z]
			self.wait(self.id(8)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value f[1][it][0][y][z]
			self.wait(self.id(2)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// name alfa[1][it][j][0][y][z]
			_out_0, 
			// name beta[1][it][j][0][y][z]
			_out_1, 
			// value alfa_beta_beg[1][it][0][y][z]
			self.wait(self.id(7)[1][self.arg(2).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// name alfa_beta_beg6[1][it][j][1][y][z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(10)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(11)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(12)[1][self.arg(2).get_int()][self.arg(3).get_int()][1][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	// req_unlimited: alfa[1][it][j][0][y][z]
	{		DF posted=self.wait(self.id(10)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(10)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[1][it][j][0][y][z]
	{		DF posted=self.wait(self.id(11)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(11)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[1][it][j][1][y][z]
	{		DF posted=self.wait(self.id(12)[1][self.arg(2).get_int()][self.arg(3).get_int()][1][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(12)[1][self.arg(2).get_int()][self.arg(3).get_int()][1][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((1)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// IF: preparations: if (size_x)>(1)
BlockRetStatus block_69(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=70;
	return CONTINUE;
}

// Request : if (size_x)>(1)
BlockRetStatus block_70(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=71;
	return CONTINUE;
}

// After requests: if (size_x)>(1)
BlockRetStatus block_71(CF &self)
{
	if (0!=static_cast<int>(((self.wait(self.id(0))).get_int())>(1))) {

// GEN BODY: if (size_x)>(1)
	{ // FORK_BI: cf calcVal_x[j][0][y][z]: calcVal((((z)*(size_y))*(size_z))+((y)*(size_x)), 1, cntstep[1][0][y][z], params[0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], u_cur[1][it][j][0][y][z], ubeg6[1][it][j][(0)-(1)][y][z], ubeg6[1][it][j][0][y][z]);
		CF *child=self.fork(72);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->id(0)=self.id(1);
		child->id(1)=self.id(2);
		child->id(2)=self.id(0);
		child->id(3)=self.id(3);
		child->id(4)=self.id(4);
		child->id(5)=self.id(5);
		child->id(6)=self.id(6);
		child->id(7)=self.id(7);
		child->id(8)=self.id(8);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf calcVal_x[j][0][y][z]: calcVal((((z)*(size_y))*(size_z))+((y)*(size_x)), 1, cntstep[1][0][y][z], params[0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], u_cur[1][it][j][0][y][z], ubeg6[1][it][j][(0)-(1)][y][z], ubeg6[1][it][j][0][y][z]);
BlockRetStatus block_72(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request cntstep[1][0][y][z]
	self.request(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request ubeg6[1][it][j][0][y][z]
	self.request(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_x
	self.request(self.id(2), CyclicLocator(0));
	// request alfa[1][it][j][0][y][z]
	self.request(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_y
	self.request(self.id(4), CyclicLocator(0));
	// request params[0][y][z]
	self.request(self.id(5)[0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// request size_z
	self.request(self.id(6), CyclicLocator(0));
	// request beta[1][it][j][0][y][z]
	self.request(self.id(7)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));

	self.NextBlock=73;
	return CONTINUE;
}

// Request : cf calcVal_x[j][0][y][z]: calcVal((((z)*(size_y))*(size_z))+((y)*(size_x)), 1, cntstep[1][0][y][z], params[0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], u_cur[1][it][j][0][y][z], ubeg6[1][it][j][(0)-(1)][y][z], ubeg6[1][it][j][0][y][z]);
BlockRetStatus block_73(CF &self)
{
	// wait cntstep[1][0][y][z]
	if (self.wait(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait ubeg6[1][it][j][0][y][z]
	if (self.wait(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}

	// wait alfa[1][it][j][0][y][z]
	if (self.wait(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(4)).is_unset()) {
		return WAIT;
	}

	// wait params[0][y][z]
	if (self.wait(self.id(5)[0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(6)).is_unset()) {
		return WAIT;
	}

	// wait beta[1][it][j][0][y][z]
	if (self.wait(self.id(7)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=74;
	return CONTINUE;
}

// After requests: cf calcVal_x[j][0][y][z]: calcVal((((z)*(size_y))*(size_z))+((y)*(size_x)), 1, cntstep[1][0][y][z], params[0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], u_cur[1][it][j][0][y][z], ubeg6[1][it][j][(0)-(1)][y][z], ubeg6[1][it][j][0][y][z]);
BlockRetStatus block_74(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_x[j][0][y][z]: calcVal((((z)*(size_y))*(size_z))+((y)*(size_x)), 1, cntstep[1][0][y][z], params[0][y][z], alfa[1][it][j][0][y][z], beta[1][it][j][0][y][z], u_cur[1][it][j][0][y][z], ubeg6[1][it][j][(0)-(1)][y][z], ubeg6[1][it][j][0][y][z]);
		calcVal(
			// int (((z)*(size_y))*(size_z))+((y)*(size_x))
			static_cast<int>((static_cast<int>((static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(4))).get_int())))*((self.wait(self.id(6))).get_int())))+(static_cast<int>((self.arg(0).get_int())*((self.wait(self.id(2))).get_int())))), 
			// int 1
			1, 
			// int cntstep[1][0][y][z]
			self.wait(self.id(0)[1][0][self.arg(0).get_int()][self.arg(1).get_int()]).get_int(), 
			// value params[0][y][z]
			self.wait(self.id(5)[0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value alfa[1][it][j][0][y][z]
			self.wait(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// value beta[1][it][j][0][y][z]
			self.wait(self.id(7)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]), 
			// name u_cur[1][it][j][0][y][z]
			_out_0, 
			// name ubeg6[1][it][j][(0)-(1)][y][z]
			_out_1, 
			// value ubeg6[1][it][j][0][y][z]
			self.wait(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>((0)-(1))][self.arg(0).get_int()][self.arg(1).get_int()], stored);
		}
	}

	self.destroy(self.id(3)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(7)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	self.destroy(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>((0)-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))));
	// req_unlimited: u_cur[1][it][j][0][y][z]
	{		DF posted=self.wait(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(8)[1][self.arg(2).get_int()][self.arg(3).get_int()][0][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[1][it][j][(0)-(1)][y][z]
	{		DF posted=self.wait(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>((0)-(1))][self.arg(0).get_int()][self.arg(1).get_int()]);
	self.post(self.id(1)[1][self.arg(2).get_int()][self.arg(3).get_int()][static_cast<int>((0)-(1))][self.arg(0).get_int()][self.arg(1).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((0)-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for x = 1 .. (size_x)-(2)
BlockRetStatus block_75(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=76;
	return CONTINUE;
}

// Request : for x = 1 .. (size_x)-(2)
BlockRetStatus block_76(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=77;
	return CONTINUE;
}

// After requests: for x = 1 .. (size_x)-(2)
BlockRetStatus block_77(CF &self)
{
	for (int _lc_x=1; _lc_x<=static_cast<int>(((self.wait(self.id(0))).get_int())-(2)); _lc_x++) {

// GEN BODY: for x = 1 .. (size_x)-(2)
	{ // FORK_BI: for j=0..(cntfor[1][x][y][z])-(1);
		CF *child=self.fork(78);
		child->arg(0)=_lc_x;
		child->arg(1)=self.arg(0).get_int();
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
		child->id(9)=self.id(0);
		child->id(10)=self.id(10);
		child->id(11)=self.id(11);
		child->id(12)=self.id(12);
		child->id(13)=self.id(13);
		child->id(14)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_FOR: for j = 0 .. (cntfor[1][x][y][z])-(1)
BlockRetStatus block_78(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request cntfor[1][x][y][z]
	self.request(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(0));

	self.NextBlock=79;
	return CONTINUE;
}

// Request : for j = 0 .. (cntfor[1][x][y][z])-(1)
BlockRetStatus block_79(CF &self)
{
	// wait cntfor[1][x][y][z]
	if (self.wait(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=80;
	return CONTINUE;
}

// After requests: for j = 0 .. (cntfor[1][x][y][z])-(1)
BlockRetStatus block_80(CF &self)
{
	for (int _lc_j=0; _lc_j<=static_cast<int>((self.wait(self.id(0)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int())-(1)); _lc_j++) {

// GEN BODY: for j = 0 .. (cntfor[1][x][y][z])-(1)
	{ // FORK_BI: cf calccoef_pr_x[j][x][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), cntstep[1][x][y][z], j, params[x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][(x)+(1)][y][z]);
		CF *child=self.fork(81);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->arg(4)=_lc_j;
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

	{ // FORK_BI: cf calcVal_x[j][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 1, cntstep[1][x][y][z], params[x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], u_cur[1][it][j][x][y][z], ubeg6[1][it][j][(x)-(1)][y][z], ubeg6[1][it][j][x][y][z]);
		CF *child=self.fork(84);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=self.arg(3).get_int();
		child->arg(4)=_lc_j;
		child->id(0)=self.id(9);
		child->id(1)=self.id(3);
		child->id(2)=self.id(13);
		child->id(3)=self.id(10);
		child->id(4)=self.id(5);
		child->id(5)=self.id(12);
		child->id(6)=self.id(7);
		child->id(7)=self.id(11);
		child->id(8)=self.id(14);
	}

	} // for
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_x[j][x][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), cntstep[1][x][y][z], j, params[x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][(x)+(1)][y][z]);
BlockRetStatus block_81(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request alfa_beta_beg6[1][it][j][x][y][z]
	self.request(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request c[1][it][x][y][z]
	self.request(self.id(1)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_y
	self.request(self.id(2), CyclicLocator(0));
	// request a[1][it][x][y][z]
	self.request(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request f[1][it][x][y][z]
	self.request(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_z
	self.request(self.id(6), CyclicLocator(0));
	// request b[1][it][x][y][z]
	self.request(self.id(7)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_x
	self.request(self.id(8), CyclicLocator(0));
	// request cntstep[1][x][y][z]
	self.request(self.id(9)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=82;
	return CONTINUE;
}

// Request : cf calccoef_pr_x[j][x][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), cntstep[1][x][y][z], j, params[x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][(x)+(1)][y][z]);
BlockRetStatus block_82(CF &self)
{
	// wait alfa_beta_beg6[1][it][j][x][y][z]
	if (self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait c[1][it][x][y][z]
	if (self.wait(self.id(1)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}

	// wait a[1][it][x][y][z]
	if (self.wait(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait f[1][it][x][y][z]
	if (self.wait(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(6)).is_unset()) {
		return WAIT;
	}

	// wait b[1][it][x][y][z]
	if (self.wait(self.id(7)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(8)).is_unset()) {
		return WAIT;
	}

	// wait cntstep[1][x][y][z]
	if (self.wait(self.id(9)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=83;
	return CONTINUE;
}

// After requests: cf calccoef_pr_x[j][x][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), cntstep[1][x][y][z], j, params[x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][(x)+(1)][y][z]);
BlockRetStatus block_83(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		DF _out_2;
		// EXEC_EXTERN cf calccoef_pr_x[j][x][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), cntstep[1][x][y][z], j, params[x][y][z], a[1][it][x][y][z], b[1][it][x][y][z], c[1][it][x][y][z], f[1][it][x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][x][y][z], alfa_beta_beg6[1][it][j][(x)+(1)][y][z]);
		calccoef_pr_x(
			// int ((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(2))).get_int())))*((self.wait(self.id(6))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(8))).get_int())))))+(self.arg(0).get_int())), 
			// int cntstep[1][x][y][z]
			self.wait(self.id(9)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// int j
			self.arg(4).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value a[1][it][x][y][z]
			self.wait(self.id(3)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value b[1][it][x][y][z]
			self.wait(self.id(7)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value c[1][it][x][y][z]
			self.wait(self.id(1)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value f[1][it][x][y][z]
			self.wait(self.id(5)[1][self.arg(3).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name alfa[1][it][j][x][y][z]
			_out_0, 
			// name beta[1][it][j][x][y][z]
			_out_1, 
			// value alfa_beta_beg6[1][it][j][x][y][z]
			self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name alfa_beta_beg6[1][it][j][(x)+(1)][y][z]
			_out_2);

		{
			DF stored=_out_0;
			self.store(self.id(10)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(11)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_2;
			self.store(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][static_cast<int>((self.arg(0).get_int())+(1))][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: alfa[1][it][j][x][y][z]
	{		DF posted=self.wait(self.id(10)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(10)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: beta[1][it][j][x][y][z]
	{		DF posted=self.wait(self.id(11)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(11)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	// req_unlimited: alfa_beta_beg6[1][it][j][(x)+(1)][y][z]
	{		DF posted=self.wait(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][static_cast<int>((self.arg(0).get_int())+(1))][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(0)[1][self.arg(3).get_int()][self.arg(4).get_int()][static_cast<int>((self.arg(0).get_int())+(1))][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())+(1)))*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_EXEC: cf calcVal_x[j][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 1, cntstep[1][x][y][z], params[x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], u_cur[1][it][j][x][y][z], ubeg6[1][it][j][(x)-(1)][y][z], ubeg6[1][it][j][x][y][z]);
BlockRetStatus block_84(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));
	// request size_y
	self.request(self.id(1), CyclicLocator(0));
	// request ubeg6[1][it][j][x][y][z]
	self.request(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request cntstep[1][x][y][z]
	self.request(self.id(3)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request params[x][y][z]
	self.request(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request beta[1][it][j][x][y][z]
	self.request(self.id(5)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// request size_z
	self.request(self.id(6), CyclicLocator(0));
	// request alfa[1][it][j][x][y][z]
	self.request(self.id(7)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));

	self.NextBlock=85;
	return CONTINUE;
}

// Request : cf calcVal_x[j][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 1, cntstep[1][x][y][z], params[x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], u_cur[1][it][j][x][y][z], ubeg6[1][it][j][(x)-(1)][y][z], ubeg6[1][it][j][x][y][z]);
BlockRetStatus block_85(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait ubeg6[1][it][j][x][y][z]
	if (self.wait(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait cntstep[1][x][y][z]
	if (self.wait(self.id(3)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait params[x][y][z]
	if (self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait beta[1][it][j][x][y][z]
	if (self.wait(self.id(5)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}

	// wait size_z
	if (self.wait(self.id(6)).is_unset()) {
		return WAIT;
	}

	// wait alfa[1][it][j][x][y][z]
	if (self.wait(self.id(7)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=86;
	return CONTINUE;
}

// After requests: cf calcVal_x[j][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 1, cntstep[1][x][y][z], params[x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], u_cur[1][it][j][x][y][z], ubeg6[1][it][j][(x)-(1)][y][z], ubeg6[1][it][j][x][y][z]);
BlockRetStatus block_86(CF &self)
{
	{
		DF _out_0;
		DF _out_1;
		// EXEC_EXTERN cf calcVal_x[j][x][y][z]: calcVal(((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x), 1, cntstep[1][x][y][z], params[x][y][z], alfa[1][it][j][x][y][z], beta[1][it][j][x][y][z], u_cur[1][it][j][x][y][z], ubeg6[1][it][j][(x)-(1)][y][z], ubeg6[1][it][j][x][y][z]);
		calcVal(
			// int ((((z)*(size_y))*(size_z))+((y)*(size_x)))+(x)
			static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(2).get_int())*((self.wait(self.id(1))).get_int())))*((self.wait(self.id(6))).get_int())))+(static_cast<int>((self.arg(1).get_int())*((self.wait(self.id(0))).get_int())))))+(self.arg(0).get_int())), 
			// int 1
			1, 
			// int cntstep[1][x][y][z]
			self.wait(self.id(3)[1][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]).get_int(), 
			// value params[x][y][z]
			self.wait(self.id(4)[self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value alfa[1][it][j][x][y][z]
			self.wait(self.id(7)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// value beta[1][it][j][x][y][z]
			self.wait(self.id(5)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]), 
			// name u_cur[1][it][j][x][y][z]
			_out_0, 
			// name ubeg6[1][it][j][(x)-(1)][y][z]
			_out_1, 
			// value ubeg6[1][it][j][x][y][z]
			self.wait(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]));

		{
			DF stored=_out_0;
			self.store(self.id(8)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
		{
			DF stored=_out_1;
			self.store(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()], stored);
		}
	}

	self.destroy(self.id(7)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(5)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	self.destroy(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))));
	// req_unlimited: u_cur[1][it][j][x][y][z]
	{		DF posted=self.wait(self.id(8)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(8)[1][self.arg(3).get_int()][self.arg(4).get_int()][self.arg(0).get_int()][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(0), -1);
	}
	// req_unlimited: ubeg6[1][it][j][(x)-(1)][y][z]
	{		DF posted=self.wait(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()]);
	self.post(self.id(2)[1][self.arg(3).get_int()][self.arg(4).get_int()][static_cast<int>((self.arg(0).get_int())-(1))][self.arg(1).get_int()][self.arg(2).get_int()], posted, CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((self.arg(0).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(1).get_int())*(2)))))+(self.arg(2).get_int())))/(16))), -1);
	}
	return EXIT;
}

// BI_FOR: for j = 0 .. (cntfor[1][(size_x)-(1)][y][z])-(1)
BlockRetStatus block_87(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=88;
	return CONTINUE;
}

// Request : for j = 0 .. (cntfor[1][(size_x)-(1)][y][z])-(1)
BlockRetStatus block_88(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=89;
	return CONTINUE;
}

// After requests: for j = 0 .. (cntfor[1][(size_x)-(1)][y][z])-(1)
BlockRetStatus block_89(CF &self)
{
	// request cntfor[1][(size_x)-(1)][y][z]
	self.request(self.id(1)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()], CyclicLocator(0));

	self.NextBlock=90;
	return CONTINUE;
}

// Request : for j = 0 .. (cntfor[1][(size_x)-(1)][y][z])-(1)
BlockRetStatus block_90(CF &self)
{
	// wait cntfor[1][(size_x)-(1)][y][z]
	if (self.wait(self.id(1)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).is_unset()) {
		return WAIT;
	}


	self.NextBlock=91;
	return CONTINUE;
}

// After requests: for j = 0 .. (cntfor[1][(size_x)-(1)][y][z])-(1)
BlockRetStatus block_91(CF &self)
{
	for (int _lc_j=0; _lc_j<=static_cast<int>((self.wait(self.id(1)[1][static_cast<int>(((self.wait(self.id(0))).get_int())-(1))][self.arg(0).get_int()][self.arg(1).get_int()]).get_int())-(1)); _lc_j++) {

// GEN BODY: for j = 0 .. (cntfor[1][(size_x)-(1)][y][z])-(1)
	{ // FORK_BI: if (size_x)>(1)
		CF *child=self.fork(92);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_j;
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
		child->id(10)=self.id(11);
		child->id(11)=self.id(12);
	}

	{ // FORK_BI: cf calcVal_x[j][(size_x)-(1)][y][z]: calcVal(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), 1, cntstep[1][(size_x)-(1)][y][z], params[(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], u_cur[1][it][j][(size_x)-(1)][y][z], ubeg6[1][it][j][(size_x)-(2)][y][z], ubeg[1][it][(size_x)-(1)][y][z]);
		CF *child=self.fork(102);
		child->arg(0)=self.arg(0).get_int();
		child->arg(1)=self.arg(1).get_int();
		child->arg(2)=self.arg(2).get_int();
		child->arg(3)=_lc_j;
		child->id(0)=self.id(0);
		child->id(1)=self.id(3);
		child->id(2)=self.id(2);
		child->id(3)=self.id(11);
		child->id(4)=self.id(12);
		child->id(5)=self.id(13);
		child->id(6)=self.id(10);
		child->id(7)=self.id(5);
		child->id(8)=self.id(14);
		child->id(9)=self.id(15);
	}

	} // for
	return EXIT;
}

// IF: preparations: if (size_x)>(1)
BlockRetStatus block_92(CF &self)
{
	if (self.migrate(CyclicLocator(0))) {
		return MIGRATE;
	}

	// request size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=93;
	return CONTINUE;
}

// Request : if (size_x)>(1)
BlockRetStatus block_93(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=94;
	return CONTINUE;
}

// After requests: if (size_x)>(1)
BlockRetStatus block_94(CF &self)
{
	if (0!=static_cast<int>(((self.wait(self.id(0))).get_int())>(1))) {

// GEN BODY: if (size_x)>(1)
	{ // FORK_BI: cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
		CF *child=self.fork(95);
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
		child->id(10)=self.id(10);
		child->id(11)=self.id(11);
	}

	} // if
	return EXIT;
}

// BI_EXEC: cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
BlockRetStatus block_95(CF &self)
{
	// request_preliminary size_x
	self.request(self.id(0), CyclicLocator(0));

	self.NextBlock=96;
	return CONTINUE;
}

// RequestPreliminary : cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
BlockRetStatus block_96(CF &self)
{
	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=97;
	return CONTINUE;
}

// After requests: cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
BlockRetStatus block_97(CF &self)
{
	if (self.migrate(CyclicLocator(static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>((static_cast<int>(((self.wait(self.id(0))).get_int())-(1)))*(2)))*(2)))+(static_cast<int>((self.arg(0).get_int())*(2)))))+(self.arg(1).get_int())))/(16))))) {
		return MIGRATE;
	}

	// request size_z
	self.request(self.id(1), CyclicLocator(0));
	// request size_x
	self.request(self.id(0), CyclicLocator(0));
	// request size_y
	self.request(self.id(2), CyclicLocator(0));

	self.NextBlock=98;
	return CONTINUE;
}

// Request : cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);
BlockRetStatus block_98(CF &self)
{
	// wait size_z
	if (self.wait(self.id(1)).is_unset()) {
		return WAIT;
	}

	// wait size_x
	if (self.wait(self.id(0)).is_unset()) {
		return WAIT;
	}

	// wait size_y
	if (self.wait(self.id(2)).is_unset()) {
		return WAIT;
	}


	self.NextBlock=99;
	return CONTINUE;
}

// After requests: cf calccoef_pr_x[j][(size_x)-(1)][y][z]: calccoef_pr_x(((((z)*(size_y))*(size_z))+(((y)+(1))*(size_x)))-(1), cntstep[1][(size_x)-(1)][y][z], j, params[(size_x)-(1)][y][z], a[1][it][(size_x)-(1)][y][z], b[1][it][(size_x)-(1)][y][z], c[1][it][(size_x)-(1)][y][z], f[1][it][(size_x)-(1)][y][z], alfa[1][it][j][(size_x)-(1)][y][z], beta[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][(size_x)-(1)][y][z], alfa_beta_beg6[1][it][j][size_x][y][z]);