function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/MtrPos */
	this.urlHashMap["ctrl:12"] = "ctrl.c:36,101&ctrl.h:50";
	/* <Root>/MtrPosTgt */
	this.urlHashMap["ctrl:32"] = "ctrl.c:37&ctrl.h:51";
	/* <Root>/IfbkPhA */
	this.urlHashMap["ctrl:37"] = "ctrl.c:141&ctrl.h:52";
	/* <Root>/Task_1khz */
	this.urlHashMap["ctrl:62"] = "ctrl.c:29";
	/* <Root>/Task_30khz */
	this.urlHashMap["ctrl:55"] = "ctrl.c:96";
	/* <Root>/PwmChA */
	this.urlHashMap["ctrl:36"] = "ctrl.c:163&ctrl.h:57";
	/* <Root>/MtrSpd */
	this.urlHashMap["ctrl:13"] = "ctrl.c:66&ctrl.h:58";
	/* <Root>/MtrSpdFil */
	this.urlHashMap["ctrl:49"] = "ctrl.c:72&ctrl.h:59";
	/* <Root>/IfbkPhATgt */
	this.urlHashMap["ctrl:115"] = "ctrl.c:61,142&ctrl.h:60";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["ctrl:94"] = "msg=rtwMsg_reducedBlock&block=ctrl:94";
	/* <S1>/Data Type Conversion1 */
	this.urlHashMap["ctrl:95"] = "msg=rtwMsg_reducedBlock&block=ctrl:95";
	/* <S1>/Gain */
	this.urlHashMap["ctrl:124"] = "ctrl.c:62";
	/* <S1>/Gain1 */
	this.urlHashMap["ctrl:125"] = "ctrl.c:67";
	/* <S1>/Gain2 */
	this.urlHashMap["ctrl:126"] = "ctrl.c:73";
	/* <S1>/Gain3 */
	this.urlHashMap["ctrl:127"] = "ctrl.c:33";
	/* <S1>/Gain4 */
	this.urlHashMap["ctrl:128"] = "ctrl.c:34";
	/* <S1>/Saturation */
	this.urlHashMap["ctrl:143"] = "ctrl.c:50,59";
	/* <S1>/Signal
Conversion */
	this.urlHashMap["ctrl:90"] = "ctrl.c:68";
	/* <S1>/Signal
Conversion1 */
	this.urlHashMap["ctrl:91"] = "ctrl.c:74";
	/* <S2>/Gain1 */
	this.urlHashMap["ctrl:130"] = "ctrl.c:139";
	/* <S2>/Gain2 */
	this.urlHashMap["ctrl:131"] = "ctrl.c:100";
	/* <S2>/Gain3 */
	this.urlHashMap["ctrl:132"] = "ctrl.c:164";
	/* <S2>/Gain4 */
	this.urlHashMap["ctrl:133"] = "ctrl.c:140";
	/* <S2>/Saturation */
	this.urlHashMap["ctrl:141"] = "ctrl.c:152,161";
	/* <S3>/Add */
	this.urlHashMap["ctrl:52:32"] = "ctrl.c:38";
	/* <S3>/Gain */
	this.urlHashMap["ctrl:52:34"] = "msg=rtwMsg_reducedBlock&block=ctrl:52:34";
	/* <S3>/Gain1 */
	this.urlHashMap["ctrl:52:35"] = "ctrl.c:35";
	/* <S3>/Subtract */
	this.urlHashMap["ctrl:52:37"] = "ctrl.c:39";
	/* <S4>/Add */
	this.urlHashMap["ctrl:53:32"] = "ctrl.c:44";
	/* <S4>/Gain */
	this.urlHashMap["ctrl:53:34"] = "ctrl.c:79";
	/* <S4>/Gain1 */
	this.urlHashMap["ctrl:53:35"] = "ctrl.c:46";
	/* <S4>/Subtract */
	this.urlHashMap["ctrl:53:37"] = "ctrl.c:31";
	/* <S5>/Discrete-Time
Integrator */
	this.urlHashMap["ctrl:52:65:71"] = "ctrl.c:32&ctrl.h:44";
	/* <S6>/Discrete-Time
Integrator */
	this.urlHashMap["ctrl:53:65:71"] = "ctrl.c:45,78&ctrl.h:45";
	/* <S7>/Add */
	this.urlHashMap["ctrl:54:32"] = "ctrl.c:146";
	/* <S7>/Gain */
	this.urlHashMap["ctrl:54:34"] = "ctrl.c:178";
	/* <S7>/Gain1 */
	this.urlHashMap["ctrl:54:35"] = "ctrl.c:148";
	/* <S7>/Subtract */
	this.urlHashMap["ctrl:54:37"] = "ctrl.c:138";
	/* <S8>/Signal
Conversion */
	this.urlHashMap["ctrl:80"] = "ctrl.c:135&ctrl.h:39";
	/* <S9>/Discrete-Time
Integrator */
	this.urlHashMap["ctrl:54:65:71"] = "ctrl.c:147,177&ctrl.h:43";
	/* <S10>/Add */
	this.urlHashMap["ctrl:47:46"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=ctrl:47:46";
	/* <S10>/Add1 */
	this.urlHashMap["ctrl:47:3"] = "ctrl.c:127";
	/* <S10>/Constant */
	this.urlHashMap["ctrl:47:45"] = "ctrl.c:128";
	/* <S10>/Constant1 */
	this.urlHashMap["ctrl:47:47"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=ctrl:47:47";
	/* <S10>/Product */
	this.urlHashMap["ctrl:47:48"] = "ctrl.c:129";
	/* <S10>/Product1 */
	this.urlHashMap["ctrl:47:50"] = "ctrl.c:130";
	/* <S10>/Unit Delay */
	this.urlHashMap["ctrl:47:6"] = "ctrl.c:131,174&ctrl.h:42";
	/* <S11>/Abs */
	this.urlHashMap["ctrl:10:16"] = "ctrl.c:117";
	/* <S11>/Add */
	this.urlHashMap["ctrl:10:17"] = "ctrl.c:98";
	/* <S11>/Add1 */
	this.urlHashMap["ctrl:10:18"] = "ctrl.c:116&ctrl.h:38";
	/* <S11>/Gain1 */
	this.urlHashMap["ctrl:10:21"] = "ctrl.c:119";
	/* <S11>/Gain2 */
	this.urlHashMap["ctrl:10:22"] = "ctrl.c:120";
	/* <S11>/Product */
	this.urlHashMap["ctrl:10:25"] = "ctrl.c:121";
	/* <S11>/Sign */
	this.urlHashMap["ctrl:10:26"] = "ctrl.c:105,114";
	/* <S11>/Sqrt */
	this.urlHashMap["ctrl:10:27"] = "ctrl.c:122";
	/* <S12>/Discrete-Time
Integrator */
	this.urlHashMap["ctrl:10:66:71"] = "ctrl.c:118,171&ctrl.h:41";
	/* <S13>/Discrete-Time
Integrator */
	this.urlHashMap["ctrl:10:67:71"] = "ctrl.c:99,168&ctrl.h:40";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ctrl"};
	this.sidHashMap["ctrl"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ctrl:62"};
	this.sidHashMap["ctrl:62"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "ctrl:55"};
	this.sidHashMap["ctrl:55"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "ctrl:52"};
	this.sidHashMap["ctrl:52"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "ctrl:53"};
	this.sidHashMap["ctrl:53"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "ctrl:52:65"};
	this.sidHashMap["ctrl:52:65"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "ctrl:53:65"};
	this.sidHashMap["ctrl:53:65"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "ctrl:54"};
	this.sidHashMap["ctrl:54"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<S8>"] = {sid: "ctrl:1"};
	this.sidHashMap["ctrl:1"] = {rtwname: "<S8>"};
	this.rtwnameHashMap["<S9>"] = {sid: "ctrl:54:65"};
	this.sidHashMap["ctrl:54:65"] = {rtwname: "<S9>"};
	this.rtwnameHashMap["<S10>"] = {sid: "ctrl:47"};
	this.sidHashMap["ctrl:47"] = {rtwname: "<S10>"};
	this.rtwnameHashMap["<S11>"] = {sid: "ctrl:10"};
	this.sidHashMap["ctrl:10"] = {rtwname: "<S11>"};
	this.rtwnameHashMap["<S12>"] = {sid: "ctrl:10:66"};
	this.sidHashMap["ctrl:10:66"] = {rtwname: "<S12>"};
	this.rtwnameHashMap["<S13>"] = {sid: "ctrl:10:67"};
	this.sidHashMap["ctrl:10:67"] = {rtwname: "<S13>"};
	this.rtwnameHashMap["<Root>/MtrPos"] = {sid: "ctrl:12"};
	this.sidHashMap["ctrl:12"] = {rtwname: "<Root>/MtrPos"};
	this.rtwnameHashMap["<Root>/MtrPosTgt"] = {sid: "ctrl:32"};
	this.sidHashMap["ctrl:32"] = {rtwname: "<Root>/MtrPosTgt"};
	this.rtwnameHashMap["<Root>/IfbkPhA"] = {sid: "ctrl:37"};
	this.sidHashMap["ctrl:37"] = {rtwname: "<Root>/IfbkPhA"};
	this.rtwnameHashMap["<Root>/Trig_1Khz"] = {sid: "ctrl:75"};
	this.sidHashMap["ctrl:75"] = {rtwname: "<Root>/Trig_1Khz"};
	this.rtwnameHashMap["<Root>/Trig_30Khz"] = {sid: "ctrl:78"};
	this.sidHashMap["ctrl:78"] = {rtwname: "<Root>/Trig_30Khz"};
	this.rtwnameHashMap["<Root>/Task_1khz"] = {sid: "ctrl:62"};
	this.sidHashMap["ctrl:62"] = {rtwname: "<Root>/Task_1khz"};
	this.rtwnameHashMap["<Root>/Task_30khz"] = {sid: "ctrl:55"};
	this.sidHashMap["ctrl:55"] = {rtwname: "<Root>/Task_30khz"};
	this.rtwnameHashMap["<Root>/PwmChA"] = {sid: "ctrl:36"};
	this.sidHashMap["ctrl:36"] = {rtwname: "<Root>/PwmChA"};
	this.rtwnameHashMap["<Root>/MtrSpd"] = {sid: "ctrl:13"};
	this.sidHashMap["ctrl:13"] = {rtwname: "<Root>/MtrSpd"};
	this.rtwnameHashMap["<Root>/MtrSpdFil"] = {sid: "ctrl:49"};
	this.sidHashMap["ctrl:49"] = {rtwname: "<Root>/MtrSpdFil"};
	this.rtwnameHashMap["<Root>/IfbkPhATgt"] = {sid: "ctrl:115"};
	this.sidHashMap["ctrl:115"] = {rtwname: "<Root>/IfbkPhATgt"};
	this.rtwnameHashMap["<S1>/MtrPosTgt"] = {sid: "ctrl:63"};
	this.sidHashMap["ctrl:63"] = {rtwname: "<S1>/MtrPosTgt"};
	this.rtwnameHashMap["<S1>/MtrPos"] = {sid: "ctrl:64"};
	this.sidHashMap["ctrl:64"] = {rtwname: "<S1>/MtrPos"};
	this.rtwnameHashMap["<S1>/MtrSpd"] = {sid: "ctrl:65"};
	this.sidHashMap["ctrl:65"] = {rtwname: "<S1>/MtrSpd"};
	this.rtwnameHashMap["<S1>/MtrSpdFil"] = {sid: "ctrl:89"};
	this.sidHashMap["ctrl:89"] = {rtwname: "<S1>/MtrSpdFil"};
	this.rtwnameHashMap["<S1>/Trigger"] = {sid: "ctrl:77"};
	this.sidHashMap["ctrl:77"] = {rtwname: "<S1>/Trigger"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "ctrl:94"};
	this.sidHashMap["ctrl:94"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Data Type Conversion1"] = {sid: "ctrl:95"};
	this.sidHashMap["ctrl:95"] = {rtwname: "<S1>/Data Type Conversion1"};
	this.rtwnameHashMap["<S1>/Gain"] = {sid: "ctrl:124"};
	this.sidHashMap["ctrl:124"] = {rtwname: "<S1>/Gain"};
	this.rtwnameHashMap["<S1>/Gain1"] = {sid: "ctrl:125"};
	this.sidHashMap["ctrl:125"] = {rtwname: "<S1>/Gain1"};
	this.rtwnameHashMap["<S1>/Gain2"] = {sid: "ctrl:126"};
	this.sidHashMap["ctrl:126"] = {rtwname: "<S1>/Gain2"};
	this.rtwnameHashMap["<S1>/Gain3"] = {sid: "ctrl:127"};
	this.sidHashMap["ctrl:127"] = {rtwname: "<S1>/Gain3"};
	this.rtwnameHashMap["<S1>/Gain4"] = {sid: "ctrl:128"};
	this.sidHashMap["ctrl:128"] = {rtwname: "<S1>/Gain4"};
	this.rtwnameHashMap["<S1>/PosCtrl"] = {sid: "ctrl:52"};
	this.sidHashMap["ctrl:52"] = {rtwname: "<S1>/PosCtrl"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "ctrl:143"};
	this.sidHashMap["ctrl:143"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/Signal Conversion"] = {sid: "ctrl:90"};
	this.sidHashMap["ctrl:90"] = {rtwname: "<S1>/Signal Conversion"};
	this.rtwnameHashMap["<S1>/Signal Conversion1"] = {sid: "ctrl:91"};
	this.sidHashMap["ctrl:91"] = {rtwname: "<S1>/Signal Conversion1"};
	this.rtwnameHashMap["<S1>/SpdCtrl"] = {sid: "ctrl:53"};
	this.sidHashMap["ctrl:53"] = {rtwname: "<S1>/SpdCtrl"};
	this.rtwnameHashMap["<S1>/IfbkPhATgt"] = {sid: "ctrl:66"};
	this.sidHashMap["ctrl:66"] = {rtwname: "<S1>/IfbkPhATgt"};
	this.rtwnameHashMap["<S1>/MtrSpdOut"] = {sid: "ctrl:87"};
	this.sidHashMap["ctrl:87"] = {rtwname: "<S1>/MtrSpdOut"};
	this.rtwnameHashMap["<S1>/MtrSpdFilOut"] = {sid: "ctrl:88"};
	this.sidHashMap["ctrl:88"] = {rtwname: "<S1>/MtrSpdFilOut"};
	this.rtwnameHashMap["<S2>/MtrPos"] = {sid: "ctrl:56"};
	this.sidHashMap["ctrl:56"] = {rtwname: "<S2>/MtrPos"};
	this.rtwnameHashMap["<S2>/IfbkPhA"] = {sid: "ctrl:58"};
	this.sidHashMap["ctrl:58"] = {rtwname: "<S2>/IfbkPhA"};
	this.rtwnameHashMap["<S2>/IfbkPhATgt"] = {sid: "ctrl:57"};
	this.sidHashMap["ctrl:57"] = {rtwname: "<S2>/IfbkPhATgt"};
	this.rtwnameHashMap["<S2>/Trigger"] = {sid: "ctrl:100"};
	this.sidHashMap["ctrl:100"] = {rtwname: "<S2>/Trigger"};
	this.rtwnameHashMap["<S2>/Gain1"] = {sid: "ctrl:130"};
	this.sidHashMap["ctrl:130"] = {rtwname: "<S2>/Gain1"};
	this.rtwnameHashMap["<S2>/Gain2"] = {sid: "ctrl:131"};
	this.sidHashMap["ctrl:131"] = {rtwname: "<S2>/Gain2"};
	this.rtwnameHashMap["<S2>/Gain3"] = {sid: "ctrl:132"};
	this.sidHashMap["ctrl:132"] = {rtwname: "<S2>/Gain3"};
	this.rtwnameHashMap["<S2>/Gain4"] = {sid: "ctrl:133"};
	this.sidHashMap["ctrl:133"] = {rtwname: "<S2>/Gain4"};
	this.rtwnameHashMap["<S2>/IfbkCtrl"] = {sid: "ctrl:54"};
	this.sidHashMap["ctrl:54"] = {rtwname: "<S2>/IfbkCtrl"};
	this.rtwnameHashMap["<S2>/Saturation"] = {sid: "ctrl:141"};
	this.sidHashMap["ctrl:141"] = {rtwname: "<S2>/Saturation"};
	this.rtwnameHashMap["<S2>/SpeedObserver"] = {sid: "ctrl:1"};
	this.sidHashMap["ctrl:1"] = {rtwname: "<S2>/SpeedObserver"};
	this.rtwnameHashMap["<S2>/MtrSpd"] = {sid: "ctrl:59"};
	this.sidHashMap["ctrl:59"] = {rtwname: "<S2>/MtrSpd"};
	this.rtwnameHashMap["<S2>/MtrSpdFil"] = {sid: "ctrl:60"};
	this.sidHashMap["ctrl:60"] = {rtwname: "<S2>/MtrSpdFil"};
	this.rtwnameHashMap["<S2>/PwmChA"] = {sid: "ctrl:61"};
	this.sidHashMap["ctrl:61"] = {rtwname: "<S2>/PwmChA"};
	this.rtwnameHashMap["<S3>/y_tgt"] = {sid: "ctrl:52:30"};
	this.sidHashMap["ctrl:52:30"] = {rtwname: "<S3>/y_tgt"};
	this.rtwnameHashMap["<S3>/y_act"] = {sid: "ctrl:52:31"};
	this.sidHashMap["ctrl:52:31"] = {rtwname: "<S3>/y_act"};
	this.rtwnameHashMap["<S3>/Add"] = {sid: "ctrl:52:32"};
	this.sidHashMap["ctrl:52:32"] = {rtwname: "<S3>/Add"};
	this.rtwnameHashMap["<S3>/Gain"] = {sid: "ctrl:52:34"};
	this.sidHashMap["ctrl:52:34"] = {rtwname: "<S3>/Gain"};
	this.rtwnameHashMap["<S3>/Gain1"] = {sid: "ctrl:52:35"};
	this.sidHashMap["ctrl:52:35"] = {rtwname: "<S3>/Gain1"};
	this.rtwnameHashMap["<S3>/Integrator"] = {sid: "ctrl:52:65"};
	this.sidHashMap["ctrl:52:65"] = {rtwname: "<S3>/Integrator"};
	this.rtwnameHashMap["<S3>/Subtract"] = {sid: "ctrl:52:37"};
	this.sidHashMap["ctrl:52:37"] = {rtwname: "<S3>/Subtract"};
	this.rtwnameHashMap["<S3>/PI_out"] = {sid: "ctrl:52:38"};
	this.sidHashMap["ctrl:52:38"] = {rtwname: "<S3>/PI_out"};
	this.rtwnameHashMap["<S4>/y_tgt"] = {sid: "ctrl:53:30"};
	this.sidHashMap["ctrl:53:30"] = {rtwname: "<S4>/y_tgt"};
	this.rtwnameHashMap["<S4>/y_act"] = {sid: "ctrl:53:31"};
	this.sidHashMap["ctrl:53:31"] = {rtwname: "<S4>/y_act"};
	this.rtwnameHashMap["<S4>/Add"] = {sid: "ctrl:53:32"};
	this.sidHashMap["ctrl:53:32"] = {rtwname: "<S4>/Add"};
	this.rtwnameHashMap["<S4>/Gain"] = {sid: "ctrl:53:34"};
	this.sidHashMap["ctrl:53:34"] = {rtwname: "<S4>/Gain"};
	this.rtwnameHashMap["<S4>/Gain1"] = {sid: "ctrl:53:35"};
	this.sidHashMap["ctrl:53:35"] = {rtwname: "<S4>/Gain1"};
	this.rtwnameHashMap["<S4>/Integrator"] = {sid: "ctrl:53:65"};
	this.sidHashMap["ctrl:53:65"] = {rtwname: "<S4>/Integrator"};
	this.rtwnameHashMap["<S4>/Subtract"] = {sid: "ctrl:53:37"};
	this.sidHashMap["ctrl:53:37"] = {rtwname: "<S4>/Subtract"};
	this.rtwnameHashMap["<S4>/PI_out"] = {sid: "ctrl:53:38"};
	this.sidHashMap["ctrl:53:38"] = {rtwname: "<S4>/PI_out"};
	this.rtwnameHashMap["<S5>/IntIn"] = {sid: "ctrl:52:65:60"};
	this.sidHashMap["ctrl:52:65:60"] = {rtwname: "<S5>/IntIn"};
	this.rtwnameHashMap["<S5>/Discrete-Time Integrator"] = {sid: "ctrl:52:65:71"};
	this.sidHashMap["ctrl:52:65:71"] = {rtwname: "<S5>/Discrete-Time Integrator"};
	this.rtwnameHashMap["<S5>/IntOut"] = {sid: "ctrl:52:65:64"};
	this.sidHashMap["ctrl:52:65:64"] = {rtwname: "<S5>/IntOut"};
	this.rtwnameHashMap["<S6>/IntIn"] = {sid: "ctrl:53:65:60"};
	this.sidHashMap["ctrl:53:65:60"] = {rtwname: "<S6>/IntIn"};
	this.rtwnameHashMap["<S6>/Discrete-Time Integrator"] = {sid: "ctrl:53:65:71"};
	this.sidHashMap["ctrl:53:65:71"] = {rtwname: "<S6>/Discrete-Time Integrator"};
	this.rtwnameHashMap["<S6>/IntOut"] = {sid: "ctrl:53:65:64"};
	this.sidHashMap["ctrl:53:65:64"] = {rtwname: "<S6>/IntOut"};
	this.rtwnameHashMap["<S7>/y_tgt"] = {sid: "ctrl:54:30"};
	this.sidHashMap["ctrl:54:30"] = {rtwname: "<S7>/y_tgt"};
	this.rtwnameHashMap["<S7>/y_act"] = {sid: "ctrl:54:31"};
	this.sidHashMap["ctrl:54:31"] = {rtwname: "<S7>/y_act"};
	this.rtwnameHashMap["<S7>/Add"] = {sid: "ctrl:54:32"};
	this.sidHashMap["ctrl:54:32"] = {rtwname: "<S7>/Add"};
	this.rtwnameHashMap["<S7>/Gain"] = {sid: "ctrl:54:34"};
	this.sidHashMap["ctrl:54:34"] = {rtwname: "<S7>/Gain"};
	this.rtwnameHashMap["<S7>/Gain1"] = {sid: "ctrl:54:35"};
	this.sidHashMap["ctrl:54:35"] = {rtwname: "<S7>/Gain1"};
	this.rtwnameHashMap["<S7>/Integrator"] = {sid: "ctrl:54:65"};
	this.sidHashMap["ctrl:54:65"] = {rtwname: "<S7>/Integrator"};
	this.rtwnameHashMap["<S7>/Subtract"] = {sid: "ctrl:54:37"};
	this.sidHashMap["ctrl:54:37"] = {rtwname: "<S7>/Subtract"};
	this.rtwnameHashMap["<S7>/PI_out"] = {sid: "ctrl:54:38"};
	this.sidHashMap["ctrl:54:38"] = {rtwname: "<S7>/PI_out"};
	this.rtwnameHashMap["<S8>/MtrPos"] = {sid: "ctrl:2"};
	this.sidHashMap["ctrl:2"] = {rtwname: "<S8>/MtrPos"};
	this.rtwnameHashMap["<S8>/D-1LPF"] = {sid: "ctrl:47"};
	this.sidHashMap["ctrl:47"] = {rtwname: "<S8>/D-1LPF"};
	this.rtwnameHashMap["<S8>/SM-Differentiator"] = {sid: "ctrl:10"};
	this.sidHashMap["ctrl:10"] = {rtwname: "<S8>/SM-Differentiator"};
	this.rtwnameHashMap["<S8>/Signal Conversion"] = {sid: "ctrl:80"};
	this.sidHashMap["ctrl:80"] = {rtwname: "<S8>/Signal Conversion"};
	this.rtwnameHashMap["<S8>/SpdEst"] = {sid: "ctrl:48"};
	this.sidHashMap["ctrl:48"] = {rtwname: "<S8>/SpdEst"};
	this.rtwnameHashMap["<S8>/SpdEstFil"] = {sid: "ctrl:11"};
	this.sidHashMap["ctrl:11"] = {rtwname: "<S8>/SpdEstFil"};
	this.rtwnameHashMap["<S9>/IntIn"] = {sid: "ctrl:54:65:60"};
	this.sidHashMap["ctrl:54:65:60"] = {rtwname: "<S9>/IntIn"};
	this.rtwnameHashMap["<S9>/Discrete-Time Integrator"] = {sid: "ctrl:54:65:71"};
	this.sidHashMap["ctrl:54:65:71"] = {rtwname: "<S9>/Discrete-Time Integrator"};
	this.rtwnameHashMap["<S9>/IntOut"] = {sid: "ctrl:54:65:64"};
	this.sidHashMap["ctrl:54:65:64"] = {rtwname: "<S9>/IntOut"};
	this.rtwnameHashMap["<S10>/FiltIn"] = {sid: "ctrl:47:2"};
	this.sidHashMap["ctrl:47:2"] = {rtwname: "<S10>/FiltIn"};
	this.rtwnameHashMap["<S10>/Add"] = {sid: "ctrl:47:46"};
	this.sidHashMap["ctrl:47:46"] = {rtwname: "<S10>/Add"};
	this.rtwnameHashMap["<S10>/Add1"] = {sid: "ctrl:47:3"};
	this.sidHashMap["ctrl:47:3"] = {rtwname: "<S10>/Add1"};
	this.rtwnameHashMap["<S10>/Constant"] = {sid: "ctrl:47:45"};
	this.sidHashMap["ctrl:47:45"] = {rtwname: "<S10>/Constant"};
	this.rtwnameHashMap["<S10>/Constant1"] = {sid: "ctrl:47:47"};
	this.sidHashMap["ctrl:47:47"] = {rtwname: "<S10>/Constant1"};
	this.rtwnameHashMap["<S10>/Product"] = {sid: "ctrl:47:48"};
	this.sidHashMap["ctrl:47:48"] = {rtwname: "<S10>/Product"};
	this.rtwnameHashMap["<S10>/Product1"] = {sid: "ctrl:47:50"};
	this.sidHashMap["ctrl:47:50"] = {rtwname: "<S10>/Product1"};
	this.rtwnameHashMap["<S10>/Unit Delay"] = {sid: "ctrl:47:6"};
	this.sidHashMap["ctrl:47:6"] = {rtwname: "<S10>/Unit Delay"};
	this.rtwnameHashMap["<S10>/FiltOut"] = {sid: "ctrl:47:7"};
	this.sidHashMap["ctrl:47:7"] = {rtwname: "<S10>/FiltOut"};
	this.rtwnameHashMap["<S11>/DiffIn"] = {sid: "ctrl:10:15"};
	this.sidHashMap["ctrl:10:15"] = {rtwname: "<S11>/DiffIn"};
	this.rtwnameHashMap["<S11>/Abs"] = {sid: "ctrl:10:16"};
	this.sidHashMap["ctrl:10:16"] = {rtwname: "<S11>/Abs"};
	this.rtwnameHashMap["<S11>/Add"] = {sid: "ctrl:10:17"};
	this.sidHashMap["ctrl:10:17"] = {rtwname: "<S11>/Add"};
	this.rtwnameHashMap["<S11>/Add1"] = {sid: "ctrl:10:18"};
	this.sidHashMap["ctrl:10:18"] = {rtwname: "<S11>/Add1"};
	this.rtwnameHashMap["<S11>/Gain1"] = {sid: "ctrl:10:21"};
	this.sidHashMap["ctrl:10:21"] = {rtwname: "<S11>/Gain1"};
	this.rtwnameHashMap["<S11>/Gain2"] = {sid: "ctrl:10:22"};
	this.sidHashMap["ctrl:10:22"] = {rtwname: "<S11>/Gain2"};
	this.rtwnameHashMap["<S11>/Integrator"] = {sid: "ctrl:10:66"};
	this.sidHashMap["ctrl:10:66"] = {rtwname: "<S11>/Integrator"};
	this.rtwnameHashMap["<S11>/Integrator1"] = {sid: "ctrl:10:67"};
	this.sidHashMap["ctrl:10:67"] = {rtwname: "<S11>/Integrator1"};
	this.rtwnameHashMap["<S11>/Product"] = {sid: "ctrl:10:25"};
	this.sidHashMap["ctrl:10:25"] = {rtwname: "<S11>/Product"};
	this.rtwnameHashMap["<S11>/Sign"] = {sid: "ctrl:10:26"};
	this.sidHashMap["ctrl:10:26"] = {rtwname: "<S11>/Sign"};
	this.rtwnameHashMap["<S11>/Sqrt"] = {sid: "ctrl:10:27"};
	this.sidHashMap["ctrl:10:27"] = {rtwname: "<S11>/Sqrt"};
	this.rtwnameHashMap["<S11>/DiffOut"] = {sid: "ctrl:10:28"};
	this.sidHashMap["ctrl:10:28"] = {rtwname: "<S11>/DiffOut"};
	this.rtwnameHashMap["<S12>/IntIn"] = {sid: "ctrl:10:66:60"};
	this.sidHashMap["ctrl:10:66:60"] = {rtwname: "<S12>/IntIn"};
	this.rtwnameHashMap["<S12>/Discrete-Time Integrator"] = {sid: "ctrl:10:66:71"};
	this.sidHashMap["ctrl:10:66:71"] = {rtwname: "<S12>/Discrete-Time Integrator"};
	this.rtwnameHashMap["<S12>/IntOut"] = {sid: "ctrl:10:66:64"};
	this.sidHashMap["ctrl:10:66:64"] = {rtwname: "<S12>/IntOut"};
	this.rtwnameHashMap["<S13>/IntIn"] = {sid: "ctrl:10:67:60"};
	this.sidHashMap["ctrl:10:67:60"] = {rtwname: "<S13>/IntIn"};
	this.rtwnameHashMap["<S13>/Discrete-Time Integrator"] = {sid: "ctrl:10:67:71"};
	this.sidHashMap["ctrl:10:67:71"] = {rtwname: "<S13>/Discrete-Time Integrator"};
	this.rtwnameHashMap["<S13>/IntOut"] = {sid: "ctrl:10:67:64"};
	this.sidHashMap["ctrl:10:67:64"] = {rtwname: "<S13>/IntOut"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
