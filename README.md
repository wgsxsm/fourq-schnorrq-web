# FourQ SchnorrQ 在线签名工具（WebAssembly）

基于 Microsoft [FourQlib](https://github.com/Microsoft/FourQlib) 官方库的纯浏览器端实现。

### 在线演示（部署后）
https://wgsxsm.github.io/fourq-schnorrq-web

### 功能
- 生成公私钥对（32+32 字节）
- 对任意消息签名（64 字节签名）
- 验证签名
- 全部在浏览器内完成，私钥永不离开本地

### 部署方式（已自动开启 GitHub Pages）
1. 确保本地已安装 Emscripten（见下方）
2. 按 `build.sh` 编译一次
3. 把生成的 `fourq.js` 和 `fourq.wasm` 上传到本仓库
4. Settings → Pages → Deploy from `main` branch → Save

5 分钟即可拥有自己的在线 FourQ 签名工具！
