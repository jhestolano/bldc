function CodeDefine() { 
this.def = new Array();
this.def["rtDW"] = {file: "ctrl_c.html",line:14,type:"var"};
this.def["rtU"] = {file: "ctrl_c.html",line:17,type:"var"};
this.def["rtY"] = {file: "ctrl_c.html",line:20,type:"var"};
this.def["Trig_1Khz"] = {file: "ctrl_c.html",line:23,type:"fcn"};
this.def["Trig_30Khz"] = {file: "ctrl_c.html",line:88,type:"fcn"};
this.def["ctrl_initialize"] = {file: "ctrl_c.html",line:187,type:"fcn"};
this.def["Ifbk"] = {file: "ctrl_h.html",line:25,type:"type"};
this.def["Degs_s"] = {file: "ctrl_h.html",line:32,type:"type"};
this.def["DW"] = {file: "ctrl_h.html",line:46,type:"type"};
this.def["ExtU"] = {file: "ctrl_h.html",line:53,type:"type"};
this.def["ExtY"] = {file: "ctrl_h.html",line:61,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:42,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:43,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:44,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:45,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:46,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:87,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "/";
var isPC = false;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ctrl_c.html"] = "../ctrl.c";
	this.html2Root["ctrl_c.html"] = "ctrl_c.html";
	this.html2SrcPath["ctrl_h.html"] = "../ctrl.h";
	this.html2Root["ctrl_h.html"] = "ctrl_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ctrl_c.html","ctrl_h.html","rtwtypes_h.html","rtmodel_h.html"];
