function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	size: 32};
	 this.metricsArray.var["rtU"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	size: 12};
	 this.metricsArray.var["rtY"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	size: 16};
	 this.metricsArray.fcn["Trig_1Khz"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["Trig_30Khz"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	stack: 16,
	stackTotal: 16};
	 this.metricsArray.fcn["ctrl_initialize"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabsf"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sqrtf"] = {file: "/home/elrobotista/dev/stm32/projects/bldc_master/mbd/codegen/ctrl_ert_rtw/ctrl.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="ctrl_metrics.html">Global Memory: 60(bytes) Maximum Stack: 16(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
